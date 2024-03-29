#ifndef VALENTINEASSEMBLER_PREPROCESSOR_HPP
#define VALENTINEASSEMBLER_PREPROCESSOR_HPP


#include <map>
#include <optional>
#include <string>
#include <filesystem>
#include <queue>
#include <stack>
#include "../util/Address.hpp"
#include "../util/Subroutine.hpp"

enum InstructionType {
    PREPROCESSOR,
    PROGRAM
};

class Preprocessor {
private:
    std::optional<Address>** setAddress;
    std::map<std::string, std::string> macros {};
    std::map<std::string, Subroutine*>* inlineSubroutines;
    std::stack<std::pair<const std::filesystem::path, std::ifstream>>* fileTrace;
    std::optional<Subroutine*>* inlineInsertion;
    std::vector<std::string>* files;

    static void stripComments (std::string& str);
    static void removeWhitespace (std::string& str);
    static InstructionType getType (std::string& str);
    static void replaceBinary(std::string& str);
    void addMacro(const std::string& macro, const std::string& alias);
    void replaceMacros(std::string& line);
    void registerAddresses(std::string& line);
    void insertFile(const std::string &file);
public:
    explicit Preprocessor(std::optional<Address> **address, std::vector<std::string> *files,
                          std::map<std::string, Subroutine *> *inlineSubroutines,
                          std::optional<Subroutine *> *inlineInsertion,
                          std::stack<std::pair<const std::filesystem::path, std::ifstream>> *fileTrace);
    InstructionType processLine (std::string& line);
};


#endif //VALENTINEASSEMBLER_PREPROCESSOR_HPP
