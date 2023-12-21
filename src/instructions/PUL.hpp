#ifndef VALENTINEASSEMBLER_PUL_HPP
#define VALENTINEASSEMBLER_PUL_HPP

#include "include/Instruction.hpp"
#include "../parameters/Register.hpp"

class PUL extends public Instruction {
private:
    Register reg;
public:
    void generate(byte *binary) override;

    constructor(PUL);
    destructor(PUL);
};


#endif //VALENTINEASSEMBLER_PUL_HPP
