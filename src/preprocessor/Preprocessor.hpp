#ifndef VALENTINEASSEMBLER_PREPROCESSOR_HPP
#define VALENTINEASSEMBLER_PREPROCESSOR_HPP


#include <map>
#include <string>

enum InstructionType {
    PREPROCESSOR,
    PROGRAM
};

class Preprocessor {
private:
    std::map<std::string, std::string> macros {};

    static void stripComments (std::string& str);
    static void removeWhitespace (std::string& str);
    static InstructionType getType (std::string& str);
    void addMacro(std::string macro, std::string alias);
public:
    InstructionType processLine (std::string& line);
};


#endif //VALENTINEASSEMBLER_PREPROCESSOR_HPP
