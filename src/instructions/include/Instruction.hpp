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
#include "../../parsing/include/Parameter.hpp"

typedef std::uint8_t byte;

#define extends :
#define constructor(instruction)                    \
    explicit instruction (std::vector<Parameter*> parameters)
#define destructor(instruction) ~instruction() = default
#define paramAs(index, type) dynamic_cast<type&>(*parameters[index])

template<class Child, class Base>
concept Derived = std::is_base_of<Base, Child>::value;

class Instruction {
protected:
    const size_t byteSize;

    explicit Instruction(size_t size) : byteSize(size){
    }

public:
    size_t size () const {
        return this->byteSize;
    }

    template<Derived<Instruction> t>
    static Instruction* factory(std::vector<Parameter*> instruction) {
        return new t(instruction);
    }

    virtual void generate(byte* binary) = 0;

};

#endif //VALENTINEASSEMBLER_INSTRUCTION_HPP
