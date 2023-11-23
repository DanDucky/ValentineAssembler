#ifndef VALENTINEASSEMBLER_INSTRUCTION_HPP
#define VALENTINEASSEMBLER_INSTRUCTION_HPP

#include <cstdint>
#include <string>
#include <iostream>
#include <utility>
#include <concepts>
#include <vector>

#include "../../parsing/Parser.hpp"
#include "../settings/opcodes.hpp"
#include "../settings/sizes.hpp"
#include "../../util/templates/ByteBuilder.hpp"

typedef std::uint8_t byte;


#define extends :
#define constructor(instruction)                    \
    explicit instruction (std::string line)
#define destructor(instruction) ~instruction() = default

template<class Child, class Base>
concept Derived = std::is_base_of<Base, Child>::value;

class Instruction {
protected:
    std::string* line;
    size_t byteSize;

    explicit Instruction(std::string* line, size_t size) {
        this->line = line;
        this->byteSize = size;
    }

public:
    size_t size () const {
        return this->byteSize;
    }

    template<Derived<Instruction> t>
    static Instruction* factory(std::string line) {
        return new t(std::move(line));
    }

    virtual void generate(byte* binary) = 0;

};

#endif //VALENTINEASSEMBLER_INSTRUCTION_HPP
