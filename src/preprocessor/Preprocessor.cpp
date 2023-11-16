#include "Preprocessor.hpp"

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
    auto pos = str.find_first_not_of(' ');
    if (pos != 0 && pos != std::string::npos) {
        str = str.substr(pos);
    }
}

InstructionType Preprocessor::processLine(std::string &line) {
    stripComments(line);
    removeWhitespace(line);

    if (getType(line) == PREPROCESSOR) {
        return PREPROCESSOR;
    }

    return PROGRAM;
}

InstructionType Preprocessor::getType(std::string &str) {
    return str[0] == '/' ? PREPROCESSOR : PROGRAM;
}

