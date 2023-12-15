#ifndef VALENTINEASSEMBLER_PROGRAM_HPP
#define VALENTINEASSEMBLER_PROGRAM_HPP

#include <map>
#include <optional>
#include <string>
#include <functional>
#include <fstream>
#include <queue>
#include <algorithm>
#include <stack>

#include "../parsing/Parser.hpp"
#include "Address.hpp"
#include "../instructions/include/InstructionLibrary.hpp"
#include "Subroutine.hpp"
#include "../preprocessor/Preprocessor.hpp"
#include "../parameters/include/Parameter.hpp"

class Program {
private:
    const InstructionSet* instructions;
    std::queue<std::string> insertions;
    std::vector<Subroutine*> processed;
    Address* passedAddress;

    Preprocessor preprocessor;
public:
    static std::map<std::string, Address> addresses;
    explicit Program(const InstructionSet& instructionSet);
    ~Program();
    void process(std::ifstream& stream);
    size_t size ();
    void compile(byte* out);
};

#endif //VALENTINEASSEMBLER_PROGRAM_HPP
