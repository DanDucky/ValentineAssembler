#ifndef VALENTINEASSEMBLER_PSH_HPP
#define VALENTINEASSEMBLER_PSH_HPP

#include "include/Instruction.hpp"
#include "../parameters/Register.hpp"

class PSH extends public Instruction {
private:
    Register reg;
public:
    constructor(PSH);
    destructor(PSH);

    void generate(byte *binary) override;
};


#endif //VALENTINEASSEMBLER_PSH_HPP
