#include "BRA.hpp"

#include <utility>

BRA::BRA(std::string line) : Instruction(&line, 2) {
}

void BRA::generate(byte * binary) {

}
