#include "POL.hpp"

void POL::generate(byte *binary) {
    ByteBuilder<POL_SIZE> builder;
    builder += POL_OPCODE;
    builder += reg;
    builder.put(binary);
}

POL::POL(Parameter **parameters) : Instruction(POL_SIZE) ,
    reg(paramAs(0, Register)) {

}
