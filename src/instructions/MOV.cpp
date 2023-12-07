#include "MOV.hpp"

void MOV::generate(byte * binary) {
    ByteBuilder<MOV_SIZE> builder;
    builder += MOV_OPCODE;
    builder += from;
    builder += to;
    builder.put(binary);
}

MOV::MOV(Parameter ** parameters) : Instruction(MOV_SIZE),
    from(paramAs(0, Register)),
    to(paramAs(1, Register)) {
}
