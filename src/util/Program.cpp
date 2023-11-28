#include "Program.hpp"

Program::Program(const InstructionSet& instructionSet) : instructions(&instructionSet), preprocessor(&addresses){

}

void Program::process(std::ifstream &stream) {
}
