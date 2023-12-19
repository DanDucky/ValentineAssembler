#ifndef VALENTINEASSEMBLER_STR_HPP
#define VALENTINEASSEMBLER_STR_HPP

#include "include/Instruction.hpp"
#include "../parameters/Register.hpp"

class STR extends public Instruction {
private:
    Register reg;
public:
    constructor(STR);
    destructor(STR);

    void generate(byte *binary) override;
};


#endif //VALENTINEASSEMBLER_STR_HPP
