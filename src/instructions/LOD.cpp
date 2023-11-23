#include "LOD.hpp"

void LOD::generate(byte *binary) {
    ByteBuilder<LOD_SIZE> builder;
    builder += LOD_OPCODE;
    builder += reg;
    builder.nextByte();
    builder += {data, 8};
    builder.get(binary);
}

LOD::LOD(std::string line) : Instruction(&line, LOD_SIZE){
    std::vector<std::string> params = Parser::splitByPrefixes(line);
    reg = Register(params[0]);
    data = std::stoi(params[1]);
}
