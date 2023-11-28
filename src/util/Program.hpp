#ifndef VALENTINEASSEMBLER_PROGRAM_HPP
#define VALENTINEASSEMBLER_PROGRAM_HPP

#include <map>
#include <optional>
#include <string>
#include <functional>
#include <fstream>

#include "Address.hpp"
#include "../instructions/include/Instruction.hpp"
#include "Subroutine.hpp"
#include "../preprocessor/Preprocessor.hpp"
#include "../parsing/include/Parameter.hpp"

typedef std::map<std::string, std::function<Instruction*(std::vector<Parameter*>)>> InstructionSet;

class Program {
private:
    std::map<std::string, std::optional<Address>> addresses {};
    const InstructionSet* instructions;
    std::vector<Subroutine> program;

    Preprocessor preprocessor;
public:
    explicit Program(const InstructionSet& instructionSet);
    void process(std::ifstream& stream);
};

#endif //VALENTINEASSEMBLER_PROGRAM_HPP
