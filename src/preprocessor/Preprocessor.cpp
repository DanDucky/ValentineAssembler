#include "Preprocessor.hpp"
#include "../parsing/Parser.hpp"
#include "../util/Program.hpp"
#include <algorithm>
#include <cstdint>

void Preprocessor::addMacro(std::string macro, std::string alias) {
    macros.insert({macro, alias});
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
            if (replaceMacros(line) == MULTI) return PREPROCESSOR;
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

MacroType Preprocessor::replaceMacros(std::string& line) {
    const auto numberOfMacros = std::ranges::count(line, USE_MACRO_PREFIX);

    if (numberOfMacros == 0) { // maybe this will fix your lifetime complaint windows?
        return INLINE;
    }

    std::string stringMacros[numberOfMacros];
    auto last = line.find(USE_MACRO_PREFIX);

    for (unsigned short i = 0; i < numberOfMacros; i++) {
        const auto next = line.find(USE_MACRO_PREFIX, last + 1);
        const auto nextPrefix = Parser::findNextPrefix(line, last + 1);
        stringMacros[i] = std::string(&line[last + 1], &line[nextPrefix != std::string::npos ? nextPrefix : line.size()]);
        last = next;
    }

    if (numberOfMacros == 1 && line == USE_MACRO_PREFIX + stringMacros[0]) { // this means we are just replacing the whole line
        const auto replaceWith = macros.find(stringMacros[0])->second;
        const auto lineCount = std::ranges::count(line, MULTI_LINE) + 1;
        std::string macroLines[lineCount];
        Parser::split(replaceWith, macroLines, lineCount, MULTI_LINE);
        for (unsigned short i = 0; i < lineCount; i++) {
            insertions->push(macroLines[i]);
        }
        return MULTI;
    }

    last = line.find(USE_MACRO_PREFIX);
    for (unsigned short i = 0; i < numberOfMacros; i++) {
        const auto next = line.find(USE_MACRO_PREFIX, last + 1);

        line.erase(last, stringMacros[i].size() + 1); // erase macro signature
        line.insert(last, macros.find(stringMacros[i])->second);

        last = next;
    }
    if (line.contains(MULTI_LINE)); // error, multi line macros present alongside other macros or other text todo
    return INLINE;
}

void Preprocessor::replaceBinary(std::string &str) {
    auto toByte = [] (const char * str) -> uint8_t { // string representing a byte to a byte
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

void Preprocessor::registerAddresses(std::string &line) {
    if (!line.contains(GET_ADDRESS_PREFIX)) return;
    const auto lastIndex = line.find_last_of(GET_ADDRESS_PREFIX);
    const std::string addressName = line.substr(lastIndex + 1);
    Program::addresses.insert({addressName, Address{}});
    *setAddress = &Program::addresses.find(addressName)->second;
}

Preprocessor::Preprocessor(std::queue<std::string> *insertions, Address** address) {
    this->insertions = insertions;
    this->setAddress = address;
}

