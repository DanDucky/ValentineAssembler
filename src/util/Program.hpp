#ifndef VALENTINEASSEMBLER_PROGRAM_HPP
#define VALENTINEASSEMBLER_PROGRAM_HPP

#include <map>
#include <optional>
#include <string>
#include <functional>
#include <fstream>
#include <queue>

#include "Address.hpp"
#include "../instructions/include/InstructionLibrary.hpp"
#include "Subroutine.hpp"
#include "../preprocessor/Preprocessor.hpp"
#include "../parameters/include/Parameter.hpp"

typedef std::map<std::string, std::function<Instruction*(std::vector<Parameter*>)>> InstructionSet;

class Program {
private:
    const InstructionSet* instructions;
    std::vector<Subroutine*> program;
    std::queue<std::string> insertions;

    Preprocessor preprocessor;
public:
    static std::map<std::string, Address> addresses;
    explicit Program(const InstructionSet& instructionSet);
    ~Program();
    void process(std::ifstream& stream);
};

#endif //VALENTINEASSEMBLER_PROGRAM_HPP
