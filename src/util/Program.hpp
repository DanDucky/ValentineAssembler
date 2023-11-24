#ifndef VALENTINEASSEMBLER_PROGRAM_HPP
#define VALENTINEASSEMBLER_PROGRAM_HPP

#include <map>
#include <optional>
#include <string>
#include <functional>

#include "Address.hpp"
#include "../instructions/include/Instruction.hpp"
#include "../parsing/Subroutine.hpp"
#include "../preprocessor/Preprocessor.hpp"

class Program {
private:
    std::map<std::string, std::optional<Address>> addresses {};
    const std::map<std::string, std::function<Instruction*(std::string)>>* instructions;
    std::vector<Subroutine> program;

    Preprocessor preprocessor;
public:
    Program(const std::map<std::string, std::function<Instruction*(std::string)>>& instructionSet);
};

#endif //VALENTINEASSEMBLER_PROGRAM_HPP
