#ifndef VALENTINEASSEMBLER_PREPROCESSOR_HPP
#define VALENTINEASSEMBLER_PREPROCESSOR_HPP


#include <map>
#include <optional>
#include <string>
#include <queue>
#include "../util/Address.hpp"

enum InstructionType {
    PREPROCESSOR,
    PROGRAM
};

class Preprocessor {
private:
    std::queue<std::string>* insertions;
    std::map<std::string, std::string> macros {};

    static void stripComments (std::string& str);
    static void removeWhitespace (std::string& str);
    static InstructionType getType (std::string& str);
    static void replaceBinary(std::string& str);
    void addMacro(std::string macro, std::string alias);
    void replaceMacros(std::string& line);
    static void registerAddresses(std::string& line);
public:
    explicit Preprocessor(std::queue<std::string>* insertions);
    InstructionType processLine (std::string& line);
};


#endif //VALENTINEASSEMBLER_PREPROCESSOR_HPP
