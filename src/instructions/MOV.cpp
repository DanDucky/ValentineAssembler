#include "MOV.hpp"
#include "../util/templates/ByteBuilder.hpp"

MOV::MOV(std::string line) : Instruction(line, MOV_SIZE) {
    std::vector<std::string> registers = Parser::splitAfter(line, REGISTER_PREFIX);
    to = Register(registers[0]);
    from = Register(registers[1]);
}

void MOV::generate(byte * binary) {
    ByteBuilder<MOV_SIZE> builder;
    builder += MOV_OPCODE;
    builder += {from.getIndex(), 3};
    builder += {to.getIndex(), 3};
    builder.get(binary);
}
