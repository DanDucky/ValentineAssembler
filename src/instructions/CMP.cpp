#include "CMP.hpp"

CMP::CMP(Parameter **parameters) : Instruction(CMP_SIZE){

}

void CMP::generate(byte *binary) {
    ByteBuilder<CMP_SIZE> builder;
    builder += CMP_OPCODE;
    builder.put(binary);
}
