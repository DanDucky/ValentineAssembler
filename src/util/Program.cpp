#include "Program.hpp"

Program::Program(const InstructionSet& instructionSet) : instructions(&instructionSet) {

}

void Program::process(std::ifstream &stream) {

}

std::map<std::string, Address> Program::addresses;