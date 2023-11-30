#include "JMP.hpp"

JMP::JMP(std::vector<Parameter *> parameters) : Instruction(JMP_SIZE),
    address(paramAs(0, SubroutineAddress)) {
}

void JMP::generate(byte *binary) {
    ByteBuilder<JMP_SIZE> builder;
    builder += JMP_OPCODE;
    builder.nextByte();
    builder += address;
    builder.put(binary);
}
