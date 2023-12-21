#include "PSH.hpp"

PSH::PSH(Parameter **parameters) : Instruction(PSH_SIZE),
    reg(paramAs(0, Register)) {
}

void PSH::generate(byte *binary) {
    ByteBuilder<PSH_SIZE> builder;
    builder += PSH_OPCODE;
    builder += reg;
    builder.put(binary);
}
