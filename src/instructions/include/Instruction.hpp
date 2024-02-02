#ifndef VALENTINEASSEMBLER_INSTRUCTION_HPP
#define VALENTINEASSEMBLER_INSTRUCTION_HPP

#include <cstdint>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <optional>

#include "../../parameters/include/Parameter.hpp"
#include "../settings/opcodes.hpp"
#include "../settings/sizes.hpp"
#include "../../util/templates/ByteBuilder.hpp"
#include "../../util/DerivedConcept.hpp"
#include "../../util/Address.hpp"

typedef std::uint8_t byte;

#define extends :
#define constructor(instruction)                    \
    explicit instruction (Parameter** parameters)
#define destructor(instruction) ~instruction() = default
#define paramAs(index, type) dynamic_cast<type&>(*(parameters[index]))

class Instruction {
protected:
    const size_t byteSize;
    std::optional<std::optional< Address >*> referenceAddress;

    explicit Instruction(size_t size) : byteSize(size){
    }

public:
    [[nodiscard]] size_t size () const {
        return this->byteSize;
    }
    void assignOffset(Address offset) {
        *referenceAddress.value() = offset;
    }
    void setReferenced(std::optional<Address>* addr) {
        referenceAddress = addr;
    }
    [[nodiscard]] bool isReferenced() const {
        return this->referenceAddress.has_value();
    }

    virtual ~Instruction()=default;

    template<Derived<Instruction> t>
    static Instruction* factory(Parameter** instruction) {
        return new t(instruction);
    }

    virtual void generate(byte* binary) = 0;

};

#endif //VALENTINEASSEMBLER_INSTRUCTION_HPP
