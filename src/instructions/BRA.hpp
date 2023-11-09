#ifndef VALENTINEASSEMBLER_BRA_HPP
#define VALENTINEASSEMBLER_BRA_HPP

#include "Instruction.hpp"

class BRA extends public Instruction {
public:

    constructor(BRA);
    factory(BRA);

    static constexpr std::string opcode = "BRA";

    byte * generate() override;
};


#endif //VALENTINEASSEMBLER_BRA_HPP
