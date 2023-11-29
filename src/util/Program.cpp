#include "Program.hpp"

std::map<std::string, Address> Program::addresses;

Program::Program(const InstructionSet& instructionSet) : instructions(&instructionSet) {

}

void Program::process(std::ifstream &stream) {
    if (!stream.is_open()) return;
    std::string line;
    while (!stream.eof()) {
        getline(stream, line);
        preprocessor.processLine(line);
        std::cout << line << "\n";
    }
}