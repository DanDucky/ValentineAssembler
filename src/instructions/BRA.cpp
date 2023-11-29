#include "BRA.hpp"

void BRA::generate(byte * binary) {
    ByteBuilder<BRA_SIZE> builder;
    builder += BRA_OPCODE;
    builder += branchFlag;
    builder.put(binary);
}

BRA::BRA(std::vector<Parameter *> parameters) : Instruction(BRA_SIZE),
    branchFlag(paramAs(0, Flag)) {
}
