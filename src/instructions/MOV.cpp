#include "MOV.hpp"

#include <utility>

byte *MOV::generate() {
    std::cout << "mov\n";
    return nullptr;
}

MOV::MOV(std::string line) : Instruction(std::move(line)) {

}
