#ifndef VALENTINEASSEMBLER_BRA_HPP
#define VALENTINEASSEMBLER_BRA_HPP

#include "include/Instruction.hpp"
#include "../parameters/Flag.hpp"
#include "../parameters/SubroutineAddress.hpp"

class BRA extends public Instruction {
private:
    Flag branchFlag;
    SubroutineAddress address;
public:

    constructor(BRA);
    destructor(BRA);

    void generate(byte* binary) override;
};


#endif //VALENTINEASSEMBLER_BRA_HPP
