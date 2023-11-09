#include "BRA.hpp"

#include <utility>

byte *BRA::generate() {
    std::cout << line << "\n";
    std::cout << "bra\n";
    return nullptr;
}

BRA::BRA(std::string line) : Instruction(std::move(line)) {

}
