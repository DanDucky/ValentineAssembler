#include "LOD.hpp"

void LOD::generate(byte *binary) {
    ByteBuilder<LOD_SIZE> builder;
    builder += LOD_OPCODE;
    builder += reg;
    builder.nextByte();
    builder += data;
    builder.put(binary);
}

LOD::LOD(Parameter** parameters) : Instruction(LOD_SIZE),
    reg(paramAs(0, Register)),
    data(paramAs(1, Value)) {
}
