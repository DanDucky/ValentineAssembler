#ifndef VALENTINEASSEMBLER_ADD_HPP
#define VALENTINEASSEMBLER_ADD_HPP

#include "include/Instruction.hpp"

class ADD extends public Instruction {
private:
public:
    constructor(ADD);
    destructor(ADD);

    void generate(byte *binary) override;
};


#endif //VALENTINEASSEMBLER_ADD_HPP
