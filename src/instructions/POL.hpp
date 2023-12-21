#ifndef VALENTINEASSEMBLER_POL_HPP
#define VALENTINEASSEMBLER_POL_HPP

#include "include/Instruction.hpp"
#include "../parameters/Register.hpp"

class POL extends public Instruction {
private:
    Register reg;
public:
    constructor(POL);
    destructor(POL);

    void generate(byte *binary) override;
};


#endif //VALENTINEASSEMBLER_POL_HPP
