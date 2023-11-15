#ifndef VALENTINEASSEMBLER_SUBROUTINE_HPP
#define VALENTINEASSEMBLER_SUBROUTINE_HPP

#include <vector>
#include <optional>
#include "../instructions/Instruction.hpp"
#include "../util/Address.hpp"

class Subroutine {
private:
    std::vector<Instruction*> instructions;
    std::optional<size_t> fixedOffset;
public:
    Subroutine() {}
    explicit Subroutine (Address address) {
        fixedOffset = address;
    }

    Subroutine* setOffset(Address address) {
        fixedOffset = address;
        return this;
    }

    bool isFixed () {
        return fixedOffset.has_value();
    }

    size_t getOffset () const {
        return fixedOffset.value();
    }

    size_t size () {
        size_t size;
        for (const auto & instruciton : instructions) {
            size += instruciton->size();
        }
        return size;
    }

    void generate(byte * output) {
        size_t position = 0;
        for (const auto & instruciton : instructions) {
            instruciton->generate(&output[position]);
            position += instruciton->size();
        }
    }
};

#endif //VALENTINEASSEMBLER_SUBROUTINE_HPP
