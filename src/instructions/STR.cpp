#include "STR.hpp"

STR::STR(Parameter **parameters) : Instruction(STR_SIZE) ,
    reg(paramAs(0, Register))
{

}

void STR::generate(byte *binary) {
    ByteBuilder<STR_SIZE> builder;
    builder += STR_OPCODE;
    builder += reg;
    builder.put(binary);
}
