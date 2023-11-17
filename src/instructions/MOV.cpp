#include "MOV.hpp"

#include <utility>

MOV::MOV(std::string line) : Instruction(std::move(line), 3) {
    to = Register("X");
    from = Register("Y");
}

void MOV::generate(byte * binary) {
}
