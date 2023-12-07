#ifndef VALENTINEASSEMBLER_CMP_HPP
#define VALENTINEASSEMBLER_CMP_HPP

#include "include/Instruction.hpp"

class CMP extends public Instruction {
private:
public:
    constructor(CMP);
    destructor(CMP);

    void generate(byte *binary) override;
};


#endif //VALENTINEASSEMBLER_CMP_HPP
