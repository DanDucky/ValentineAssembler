#include "MOV.hpp"

MOV::MOV(std::string line) : Instruction(&line, MOV_SIZE) {
    std::vector<std::string> registers = Parser::splitByPrefixes(line);
    to = Register(registers[0]);
    from = Register(registers[1]);
}

void MOV::generate(byte * binary) {
    ByteBuilder<MOV_SIZE> builder;
    builder += MOV_OPCODE;
    builder += from;
    builder += to;
    builder.get(binary);
}
