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

enum MacroType {
    INLINE,
    MULTI
};

class Preprocessor {
private:
    std::queue<std::string>* insertions;
    std::optional<Address>** setAddress;
    std::map<std::string, std::string> macros {};
    std::vector<std::string>* files;

    static void stripComments (std::string& str);
    static void removeWhitespace (std::string& str);
    static InstructionType getType (std::string& str);
    static void replaceBinary(std::string& str);
    void addMacro(std::string macro, std::string alias);
    MacroType replaceMacros(std::string& line);
    void registerAddresses(std::string& line);
    void insertFile(const std::string &file);
public:
    explicit Preprocessor(std::queue<std::string>* insertions, std::optional<Address>** address, std::vector<std::string>* files);
    InstructionType processLine (std::string& line);
};


#endif //VALENTINEASSEMBLER_PREPROCESSOR_HPP
