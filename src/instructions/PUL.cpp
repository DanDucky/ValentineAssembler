#include "PUL.hpp"

PUL::PUL(Parameter **parameters) : Instruction(PUL_SIZE),
    reg(paramAs(0, Register)) {

}

void PUL::generate(byte *binary) {
    ByteBuilder<PUL_SIZE> builder;
    builder += PUL_OPCODE;
    builder += reg;
    builder.put(binary);
}
