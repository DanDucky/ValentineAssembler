#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "instructions/Instruction.hpp"
#include "instructions/InstructionLibrary.hpp"
#include "parsing/Subroutine.hpp"
#include "util/templates/ByteBuilder.hpp"
#include "parsing/Parser.hpp"
#include "preprocessor/Preprocessor.hpp"

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

using namespace std;

int main() {
    vector<Subroutine> lines {};
    Subroutine origin = Subroutine({0,0});
    Subroutine interrupt = Subroutine({1,0});

    const std::map<string, function<Instruction*(std::string)>> parser = {
            vals(MOV),
            vals(BRA)
    };
    auto element = parser.find("MOV");
    if (element != parser.end()) {
        Preprocessor processor;
        string yobro = "  MOV  %  STACK1  %  STACK2   ";
        if (processor.processLine(yobro) == PROGRAM) {
            origin.addInstruction(element->second(yobro));
        }
    }
    uint8_t yobro[origin.size()];
    origin.generate(yobro);
    for (int i =0 ; i < origin.size(); i++) {
        cout << std::bitset<8>(yobro[i]) << "\n";
    }
}
