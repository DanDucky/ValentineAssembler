#ifndef VALENTINEASSEMBLER_BRA_HPP
#define VALENTINEASSEMBLER_BRA_HPP

#include "include/Instruction.hpp"
#include "../parsing/Flag.hpp"

class BRA extends public Instruction {
private:
    Flag branchFlag;
public:

    constructor(BRA);
    destructor(BRA);

    void generate(byte* binary) override;
};


#endif //VALENTINEASSEMBLER_BRA_HPP
