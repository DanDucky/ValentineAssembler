#include "Subroutine.hpp"

void Subroutine::generate(byte *output) {
    size_t position = 0;
    for (const auto & instruction : instructions) {
        instruction->generate(&output[position]);

        position += instruction->size();
    }
}

size_t Subroutine::size() {
    size_t size = 0;
    for (const auto & instruction : instructions) {
        size += instruction->size();
    }
    return size;
}

void Subroutine::assignReferences() {
    size_t size = fixedOffset.value(); // if this fails then all hell has gone loose
    for (const auto& instruction : instructions) {
        if (instruction->isReferenced()) {
            instruction->assignOffset(Address::addressFromOffset(size));
        }

        size += instruction->size();
    }
}

Address Subroutine::getOffset() const {
    return fixedOffset.value();
}

bool Subroutine::isFixed() {
    return fixedOffset.has_value();
}

Subroutine *Subroutine::setOffset(Address address) {
    this->fixedOffset = address;
    return this;
}

Subroutine *Subroutine::addInstruction(Instruction *instruction) {
    instructions.push_back(instruction);
    return this;
}

Subroutine::~Subroutine() {
    for (const Instruction* instruction : instructions) {
        delete instruction;
    }
}

Subroutine::Subroutine(Address address) {
    fixedOffset = address;
}

size_t Subroutine::numberOfInstructions() {
    return instructions.size();
}

bool Subroutine::getIsInline() const {
    return isInline;
}
