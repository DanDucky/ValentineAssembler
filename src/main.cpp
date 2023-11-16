#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "instructions/Instruction.hpp"
#include "instructions/InstructionLibrary.hpp"
#include "parsing/Subroutine.hpp"

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

using namespace std;

void freeInstructions(std::vector<Instruction*>& instructions) {
    for (Instruction* element : instructions) {
        delete element;
    }
}

int main() {

    vector<Subroutine> lines {};
    Subroutine origin = Subroutine({0,0});
    Subroutine interrupt = Subroutine({1,0});

    const std::map<string, function<Instruction*(std::string)>> parser = {
        vals(MOV),
        vals(BRA)
    };
    auto element = parser.find("BRA");
    if (element != parser.end()) {
        origin.addInstruction(element->second("BRA nyorm"));
    }

    for (auto& instruction: lines) {
//        instruction->generate();
    }

//    freeInstructions(lines);
}
