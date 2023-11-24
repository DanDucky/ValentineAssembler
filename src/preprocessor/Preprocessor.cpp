#include "Preprocessor.hpp"
#include "../parsing/Parser.hpp"
#include <algorithm>
#include <cstdint>

void Preprocessor::addMacro(std::string macro, std::string alias) {
    macros.insert({macro, alias});
}

void Preprocessor::stripComments(std::string &str) {
    const auto pos = str.find(';');
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

    InstructionType type = getType(line);
    switch(type) {
        case PREPROCESSOR: {
            const auto middle = &line[line.find('=')];
            addMacro(std::string(&line[1], middle), std::string(middle + 1, &line[line.size()]));
        }
            break;
        case PROGRAM: {
            if (line[0] == '\\') {
                replaceMacros(line);
            }
            replaceBinary(line);
            registerAddresses(line);
        }
            break;
        default: {

        }
            break;
    }

    return type;
}

InstructionType Preprocessor::getType(std::string &str) {
    if (std::find(prefixes.begin(), prefixes.end(), str[0]) == prefixes.end()) { // if the string begins with another prefix
        // TODO throw some error about it not being a valid command
    }
    return str[0] == '/' ? PREPROCESSOR : PROGRAM;
}

void Preprocessor::replaceMacros(std::string& line) { // only full line macros for now
    const auto macro = macros.find(std::string(&line[1], &line[line.size()]));
    if (macro != macros.end()) { // if it exists
        line = macro->second;
    } else {
    // TODO error for macro not found
    }
}

void Preprocessor::replaceBinary(std::string &str) {
    auto toByte = [] (const char * str) -> uint8_t { // string representing a byte to a byte
        uint8_t out = 0;
        for (short i = 7; i > -1; i--) {
            out |= (str[i] == '0' ? 0 : 1) << (7 - i);
        }
        return out;
    };

    auto lastIndex = str.find('!');
    auto const count = std::ranges::count(str, '!');
    for (unsigned int i = 0; i < count; i++) {
        str.insert(lastIndex + 9, std::to_string(toByte(&str[lastIndex + 1])));
        str.erase(lastIndex, 9);
        lastIndex = str.find('!');
    }
}

Preprocessor::Preprocessor(std::map<std::string, std::optional<Address>> *addresses) {
    this->addresses = addresses;
}

void Preprocessor::registerAddresses(std::string &line) {
    if (!line.contains('&')) return;
    const auto lastIndex = line.find('&');
    addresses->insert({line.substr(lastIndex + 1), std::optional<Address>()});
}

