#ifndef VALENTINEASSEMBLER_INSTRUCTION_HPP
#define VALENTINEASSEMBLER_INSTRUCTION_HPP

#include <cstdint>
#include <string>
#include <iostream>
#include <utility>
#include <concepts>
#include <vector>

#include "../parsing/Parser.hpp"

typedef std::uint8_t byte;

// arith
#define BOR_SIZE
#define AND_SIZE
#define XOR_SIZE
#define NOT_SIZE
#define ADD_SIZE
#define SUB_SIZE
#define ASL_SIZE
#define ASR_SIZE
#define ROL_SIZE
#define ROR_SIZE

// program  SIZE
#define BRA_SIZE
#define JMP_SIZE
#define LOD_SIZE

// memory   SIZE
#define STR_SIZE
#define PUL_SIZE
#define PSH_SIZE
#define POL_SIZE

#define MOV_SIZE 1

// arith
#define BOR_OPCODE {0b000010, 6}
#define AND_OPCODE {0b000110, 6}
#define XOR_OPCODE {0b001010, 6}
#define NOT_OPCODE {0b001110, 6}
#define ADD_OPCODE {0b010010, 6}
#define SUB_OPCODE {0b010110, 6}
#define ASL_OPCODE {0b011010, 6}
#define ASR_OPCODE {0b011110, 6}
#define ROL_OPCODE {0b100010, 6}
#define ROR_OPCODE {0b100110, 6}

// program
#define BRA_OPCODE {0b0001, 4}
#define JMP_OPCODE {0b0101, 4}
#define LOD_OPCODE {0b1101, 4}

// memory
#define STR_OPCODE {0b0000, 4}
#define PUL_OPCODE {0b0100, 4}
#define PSH_OPCODE {0b1000, 4}
#define POL_OPCODE {0b1100, 4}

#define MOV_OPCODE {0b11, 2}

#define extends :
#define constructor(instruction)                    \
    explicit instruction (std::string line)
#define destructor(instruction) ~instruction() = default

template<class Child, class Base>
concept Derived = std::is_base_of<Base, Child>::value;

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
        return this->byteSize;
    }

    template<Derived<Instruction> t>
    static Instruction* factory(std::string line) {
        return new t(std::move(line));
    }

    virtual void generate(byte* binary) = 0;

};

#endif //VALENTINEASSEMBLER_INSTRUCTION_HPP
