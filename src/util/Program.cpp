//
// Created by danducky on 11/23/23.
//

#include "Program.hpp"

Program::Program(const std::map<std::string, std::function<Instruction *(std::string)>>& instructionSet) : instructions(&instructionSet), preprocessor(&addresses){

}
