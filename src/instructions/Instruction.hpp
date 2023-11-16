#ifndef VALENTINEASSEMBLER_INSTRUCTION_HPP
#define VALENTINEASSEMBLER_INSTRUCTION_HPP

#include <cstdint>
#include <string>
#include <iostream>
#include <utility>

typedef std::uint8_t byte;

#define extends :
#define constructor(instruction)                    \
    explicit instruction (std::string line)

class Instruction {
protected:
    std::string line;
    size_t byteSize;

    explicit Instruction(std::string line, size_t size) {
        this->line = std::move(line);
        this->byteSize = size;
    }

public:
    size_t size () const {
        return byteSize;
    }


    template<typename t>
    static Instruction* factory(std::string line) {
        return new t(std::move(line));
    }

    virtual void generate(byte* binary) = 0;

};

#endif //VALENTINEASSEMBLER_INSTRUCTION_HPP
