#ifndef VALENTINEASSEMBLER_BRA_HPP
#define VALENTINEASSEMBLER_BRA_HPP

#include "Instruction.hpp"

class BRA extends public Instruction {
public:

    constructor(BRA);
    destructor(BRA);

    void generate(byte* binary) override;
};


#endif //VALENTINEASSEMBLER_BRA_HPP
