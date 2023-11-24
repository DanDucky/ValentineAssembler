#ifndef VALENTINEASSEMBLER_PREPROCESSOR_HPP
#define VALENTINEASSEMBLER_PREPROCESSOR_HPP


#include <map>
#include <optional>
#include <string>
#include "../util/Address.hpp"

enum InstructionType {
    PREPROCESSOR,
    PROGRAM
};

class Preprocessor {
private:
    std::map<std::string, std::string> macros {};
    std::map<std::string, std::optional<Address>>* addresses {};

    static void stripComments (std::string& str);
    static void removeWhitespace (std::string& str);
    static InstructionType getType (std::string& str);
    static void replaceBinary(std::string& str);
    void addMacro(std::string macro, std::string alias);
    void replaceMacros(std::string& line);
    void registerAddresses(std::string& line);
public:
    Preprocessor(std::map<std::string, std::optional<Address>>* addresses);
    InstructionType processLine (std::string& line);
};


#endif //VALENTINEASSEMBLER_PREPROCESSOR_HPP
