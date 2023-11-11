#ifndef VALENTINEASSEMBLER_INSTRUCTION_HPP
#define VALENTINEASSEMBLER_INSTRUCTION_HPP

#include <cstdint>
#include <string>
#include <iostream>
#include <utility>

typedef std::uint8_t byte;

#define extends :

class Instruction {
protected:
    std::string line;

    explicit Instruction(std::string line) {
        this->line = std::move(line);
    }

public:
    static void stripComments (std::string& str) {
        const auto pos = str.find(';');
        if (pos != std::string::npos) {
            str.resize(pos);
        }
    }

    template<typename t>
    static Instruction* factory(std::string line) {
        return new t(std::move(line));
    }

    virtual byte* generate() = 0;

#define constructor(instruction)                    \
    explicit instruction (std::string line)
};

#endif //VALENTINEASSEMBLER_INSTRUCTION_HPP
