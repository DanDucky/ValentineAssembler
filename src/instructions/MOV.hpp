#ifndef VALENTINEASSEMBLER_MOV_HPP
#define VALENTINEASSEMBLER_MOV_HPP

#include "include/Instruction.hpp"
#include "../parameters/Register.hpp"

class MOV extends public Instruction {
private:
    Register from;
    Register to;
public:

    constructor(MOV);
    destructor(MOV);

    void generate(byte* binary) override;
};


#endif //VALENTINEASSEMBLER_MOV_HPP
