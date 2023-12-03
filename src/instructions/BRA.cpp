#include "BRA.hpp"

void BRA::generate(byte * binary) {
    ByteBuilder<BRA_SIZE> builder;
    builder += BRA_OPCODE;
    builder += branchFlag;
    builder.nextByte();
    builder += address;
    builder.put(binary);
}

BRA::BRA(Parameter ** parameters) : Instruction(BRA_SIZE),
    branchFlag(paramAs(0, Flag)),
    address(paramAs(1, SubroutineAddress)) {
}
