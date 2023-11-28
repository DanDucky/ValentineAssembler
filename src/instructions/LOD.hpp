#ifndef VALENTINEASSEMBLER_LOD_HPP
#define VALENTINEASSEMBLER_LOD_HPP

#include "include/Instruction.hpp"
#include "../parsing/Register.hpp"
#include "../parsing/Value.hpp"

class LOD extends public Instruction {
private:
    Value data;
    Register reg;
public:

    constructor(LOD);
    destructor(LOD);

    void generate(byte* binary) override;
};


#endif //VALENTINEASSEMBLER_LOD_HPP
