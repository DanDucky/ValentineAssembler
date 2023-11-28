#include "MOV.hpp"

MOV::MOV(std::vector<Parameter *> parameters) : Instruction(MOV_SIZE),
    to(paramAs(0, Register)),
    from(paramAs(1, Register)) {

}

void MOV::generate(byte * binary) {
    ByteBuilder<MOV_SIZE> builder;
    builder += MOV_OPCODE;
    builder += from;
    builder += to;
    builder.get(binary);
}
