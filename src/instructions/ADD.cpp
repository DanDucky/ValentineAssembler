#include "ADD.hpp"

ADD::ADD(Parameter ** parameters) : Instruction(ADD_SIZE) {

}

void ADD::generate(byte *binary) {
    ByteBuilder<ADD_SIZE> builder;
    builder += ADD_OPCODE;
    builder.put(binary);
}
