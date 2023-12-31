#ifndef VALENTINEASSEMBLER_SINGLEINSTRUCTION_HPP
#define VALENTINEASSEMBLER_SINGLEINSTRUCTION_HPP

#include "Instruction.hpp"

#define concatMacro(one, two) one##two
#define single(instruction) \
class instruction : public SingleInstruction { \
    public:                 \
        constructor(instruction) : SingleInstruction(concatMacro(instruction, _OPCODE)) {} }

class SingleInstruction extends public Instruction {
private:
    const Bits opcode;
protected:
    void generate(byte *binary) override {
        ByteBuilder<1> builder;
        builder += opcode;
        builder.put(binary);
    }
public:
    explicit SingleInstruction(const Bits& _opcode) : Instruction(1) , opcode(_opcode) {
    }
    ~SingleInstruction() override =default;
};


#endif //VALENTINEASSEMBLER_SINGLEINSTRUCTION_HPP
