#ifndef VALENTINEASSEMBLER_MOV_HPP
#define VALENTINEASSEMBLER_MOV_HPP

#include "Instruction.hpp"

class MOV extends public Instruction {
public:

    constructor(MOV);

    void generate(byte* binary) override;
};


#endif //VALENTINEASSEMBLER_MOV_HPP
