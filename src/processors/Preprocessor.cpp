#include "Preprocessor.hpp"
#include "../util/Parser.hpp"
#include "Compiler.hpp"
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <queue>
#include <optional>
#include <stack>

void Preprocessor::addMacro(const std::string& macro, const std::string& alias) {
    if (macro == "INCLUDE") {
        // include whole file
        insertFile(alias);
    } else {
        macros.insert({macro, alias});
    }
}

void Preprocessor::stripComments(std::string &str) {
    const auto pos = str.find(COMMENT_PREFIX);
    if (pos != std::string::npos) {
        str.resize(pos);
    }
}

void Preprocessor::removeWhitespace(std::string &str) {
    std::erase(str, ' ');
}

InstructionType Preprocessor::processLine(std::string &line) {
    stripComments(line);
    removeWhitespace(line);

    const InstructionType type = getType(line);
    switch(type) {
        case PREPROCESSOR: {
            if (line[0] == DEFINE_MACRO_PREFIX) {
                const auto middle = &line[line.find('=')];
                addMacro(std::string(&line[1], middle), std::string(middle + 1, &line[line.size()]));
            }
        }
            break;
        case PROGRAM: {
            replaceMacros(line);
            replaceBinary(line);
            registerAddresses(line);
        }
            break;
        default: {
            // ermmmm what the scallop
        }
    }

    return type;
}

InstructionType Preprocessor::getType(std::string &str) {
//    if (std::find(prefixes.begin(), prefixes.end(), str[0]) == prefixes.end()) { // if the string begins with another prefix
//        // TODO throw some error about it not being a valid command
//    }
    return str[0] == DEFINE_MACRO_PREFIX || str.empty() ? PREPROCESSOR : PROGRAM;
}

void Preprocessor::replaceMacros(std::string& line) {
    const auto numberOfMacros = std::ranges::count(line, USE_MACRO_PREFIX);

    if (numberOfMacros == 0) { // maybe this will fix your lifetime complaint windows?
        return;
    }
    auto last = line.find(USE_MACRO_PREFIX);

    while (line.contains(USE_MACRO_PREFIX)) {
        const auto nextPrefix = Parser::findNextPrefix(line, last + 1);
        const std::string macroAlias = std::string(&line[last + 1], &line[nextPrefix != std::string::npos ? nextPrefix : line.size()]);
        line.erase(last, macroAlias.size() + 1);
        const auto macro = macros.find(macroAlias);
        if (macro == macros.end()) {
            const auto inlineSubroutine = inlineSubroutines->find(macroAlias);
            if (inlineSubroutine != inlineSubroutines->end()) {
                *inlineInsertion = inlineSubroutine->second;
                return;
            }
        } else {
            line.insert(last,macro->second);
        }
        const auto next = line.find(USE_MACRO_PREFIX, last);
        last = next;
    }
}

void Preprocessor::replaceBinary(std::string &str) {
    const auto toByte = [] (const char * str) -> uint8_t { // string representing a byte to a byte
        uint8_t out = 0;
        for (short i = 7; i > -1; i--) {
            out |= (str[i] == '0' ? 0 : 1) << (7 - i);
        }
        return out;
    };

    auto lastIndex = str.find(BINARY_PREFIX);
    auto const count = std::ranges::count(str, BINARY_PREFIX);
    for (unsigned int i = 0; i < count; i++) {
        str.insert(lastIndex + 9, std::to_string(toByte(&str[lastIndex + 1])));
        str.erase(lastIndex, 9);
        lastIndex = str.find(BINARY_PREFIX);
    }
}

void Preprocessor::registerAddresses(std::string &line) { // todo if this gets called during an inline function, it shouldn't be lol
    if (!line.contains(GET_ADDRESS_PREFIX)) return;
    const auto lastIndex = line.find_last_of(GET_ADDRESS_PREFIX);
    const std::string addressName = line.substr(lastIndex + 1);
    Compiler::addresses.insert({addressName, std::optional<Address>()});
    *setAddress = &Compiler::addresses.find(addressName)->second;
}

Preprocessor::Preprocessor(std::optional<Address> **address, std::vector<std::string> *files,
                           std::map<std::string, Subroutine *> *inlineSubroutines,
                           std::optional<Subroutine *> *inlineInsertion,
                           std::stack<std::pair<const std::filesystem::path, std::ifstream>> *fileTrace)
        : inlineSubroutines(inlineSubroutines), inlineInsertion(inlineInsertion), fileTrace(fileTrace) {
    this->setAddress = address;
    this->files = files;
}

void Preprocessor::insertFile(const std::string &file) {
    const std::filesystem::path newFile(file);
    const std::filesystem::path path = newFile.is_absolute() ? newFile : std::filesystem::path(fileTrace->top().first.parent_path() / newFile);
    files->push_back(path.filename().string());
    fileTrace->emplace(path, std::ifstream(path));
}

