#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "instructions/Instruction.hpp"
#include "instructions/InstructionLibrary.hpp"
#include "parsing/Subroutine.hpp"
#include "util/ByteBuilder.hpp"

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

using namespace std;

void freeInstructions(std::vector<Instruction*>& instructions) {
    for (Instruction* element : instructions) {
        delete element;
    }
}

int main() {

    ByteBuilder<4> test;
    cout << test.getBlock() << "\n";
    test += {0b101, 3};
    cout << test.getBlock() << "\n";
    test += {7, 3};
    cout << test.getBlock() << "\n";
    test += {7, 2};
    cout << test.getBlock() << "\n";
    test += {7, 3};
    cout << test.getBlock() << "\n";

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
