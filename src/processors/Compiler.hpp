#ifndef VALENTINEASSEMBLER_COMPILER_HPP
#define VALENTINEASSEMBLER_COMPILER_HPP

#include <map>
#include <optional>
#include <string>
#include <functional>
#include <fstream>
#include <queue>
#include <algorithm>
#include <stack>

#include "../util/Parser.hpp"
#include "../util/Address.hpp"
#include "../instructions/include/InstructionLibrary.hpp"
#include "../util/Subroutine.hpp"
#include "../processors/Preprocessor.hpp"
#include "../parameters/include/Parameter.hpp"

class Compiler {
private:
    const InstructionSet* instructions;
    std::queue<std::string> insertions;
    std::vector<Subroutine*> processed;
    Address* passedAddress;

    Preprocessor preprocessor;
public:
    static std::map<std::string, Address> addresses;
    explicit Compiler(const InstructionSet& instructionSet);
    ~Compiler();
    void process(std::ifstream& stream);
    size_t size ();
    void compile(byte* out);
};

#endif //VALENTINEASSEMBLER_COMPILER_HPP
