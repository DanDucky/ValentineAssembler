#ifndef VALENTINEASSEMBLER_MOV_HPP
#define VALENTINEASSEMBLER_MOV_HPP

#include "Instruction.hpp"

class MOV extends public Instruction {
public:

    constructor(MOV);
    factory(MOV);

    byte * generate() override;
};


#endif //VALENTINEASSEMBLER_MOV_HPP
