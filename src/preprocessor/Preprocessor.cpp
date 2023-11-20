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
        }
            break;
        default: {

        }
            break;
    }

    return type;
}

InstructionType Preprocessor::getType(std::string &str) {
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

