#ifndef VALENTINEASSEMBLER_INLINESUBROUTINEINSTRUCTION_HPP
#define VALENTINEASSEMBLER_INLINESUBROUTINEINSTRUCTION_HPP

#include "Instruction.hpp"
#include "../../util/Subroutine.hpp"

class InlineSubroutineInstruction extends public Instruction {
private:
    Subroutine* subroutine;
public:
    ~InlineSubroutineInstruction() override=default;
    explicit InlineSubroutineInstruction(Subroutine* inlineSubroutine) : Instruction(inlineSubroutine->size()), subroutine(inlineSubroutine){
    }
    void generate(byte *binary) override {
        subroutine->generate(binary);
    }
};

#endif //VALENTINEASSEMBLER_INLINESUBROUTINEINSTRUCTION_HPP
