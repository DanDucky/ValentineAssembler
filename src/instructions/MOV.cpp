#include "MOV.hpp"

#include <utility>

MOV::MOV(std::string line) : Instruction(std::move(line), 3) {
}

void MOV::generate(byte * binary) {
}
