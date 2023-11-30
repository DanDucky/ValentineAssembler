#include "Program.hpp"

std::map<std::string, Address> Program::addresses;

Program::Program(const InstructionSet& instructionSet) : instructions(&instructionSet) {

}

void Program::process(std::ifstream &stream) {
    if (!stream.is_open()) return;
    std::string line;
    unsigned int lineNum = 0;
    while (!stream.eof()) {
        lineNum++;
        getline(stream, line);
        preprocessor.processLine(line);
        std::cout << line << "\n";
    }
}