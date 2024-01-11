#ifndef VALENTINEASSEMBLER_PRINTER_HPP
#define VALENTINEASSEMBLER_PRINTER_HPP

#define CROSS "┼"
#define VERTICAL_LINE "│"
#define HORIZONTAL_LINE "─"
#define BOTTOM_LEFT_CURVE "╰"
#define TOP_RIGHT_CURVE "╮"
#define TOP_LEFT_CURVE "╭"
#define BOTTOM_RIGHT_CURVE "╯"
#define RIGHT_ARROW ">"
#define DOWNWARD_CROSS "┬"
#define UPWARD_CROSS "┴"
#define RIGHT_CROSS "├"
#define LEFT_CROSS "┤"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdio>

#include "../instructions/include/Instruction.hpp"
#include "Parser.hpp"
#include "Binary.hpp"

class Printer {
private:
    const unsigned int leftBufferSize;

    static std::string buffer(size_t size, const std::string& ch);
    static unsigned int sizeOfInt(unsigned int n);
public:
    explicit Printer(size_t file);
    void printInstruction(std::string &line, Instruction *instruction, std::pair<size_t, size_t> lineNum, long time) const;
    void printSubroutine(const std::string &line, size_t lineNum) const;
    void printStats(std::vector<std::string>* files, unsigned long time) const;
    void printHexDump(const uint8_t*, size_t size) const;
};


#endif //VALENTINEASSEMBLER_PRINTER_HPP
