#ifndef VALENTINEASSEMBLER_JMP_HPP
#define VALENTINEASSEMBLER_JMP_HPP

#include "include/Instruction.hpp"
#include "../parameters/SubroutineAddress.hpp"

class JMP extends public Instruction {
private:
    SubroutineAddress address;
public:

    constructor(JMP);
    destructor(JMP);

    void generate(byte *binary) override;
};


#endif //VALENTINEASSEMBLER_JMP_HPP
