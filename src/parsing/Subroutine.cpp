#include "Subroutine.hpp"

void Subroutine::generate(byte *output) {
    size_t position = 0;
    for (const auto & instruciton : instructions) {
        instruciton->generate(&output[position]);
        position += instruciton->size();
    }
}

size_t Subroutine::size() {
    size_t size;
    for (const auto & instruciton : instructions) {
        size += instruciton->size();
    }
    return size;
}

size_t Subroutine::getOffset() const {
    return fixedOffset.value();
}

bool Subroutine::isFixed() {
    return fixedOffset.has_value();
}

Subroutine *Subroutine::setOffset(Address address) {
    fixedOffset = address;
    return this;
}

Subroutine *Subroutine::addInstruction(Instruction *instruction) {
    instructions.push_back(instruction);
    return this;
}

Subroutine::~Subroutine() {
    for (const auto & instruciton : instructions) {
        delete instruciton;
    }
}

Subroutine::Subroutine(Address address) {
    fixedOffset = address;
}
