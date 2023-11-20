#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <chrono>

#include "instructions/include/Instruction.hpp"
#include "instructions/include/InstructionLibrary.hpp"
#include "parsing/Subroutine.hpp"
#include "util/templates/ByteBuilder.hpp"
#include "preprocessor/Preprocessor.hpp"

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

using namespace std;

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    vector<Subroutine> lines {};
    Subroutine origin = Subroutine({0,0});
    Subroutine interrupt = Subroutine({1,0});

    const std::map<string, function<Instruction*(std::string)>> parser = {
            vals(MOV),
            vals(BRA)
    };
    Preprocessor processor;
    string tone = "/MOVER  =  MOV  %  STACK1  %  STACK2   ";
    processor.processLine(tone);
    string preTest = "\\MOVER";
    processor.processLine(preTest);
    auto element = parser.find(string(&preTest[0], &preTest[3]));
    if (element != parser.end()) {
        origin.addInstruction(element->second(tone));
    }
    uint8_t yobro[origin.size()];
    origin.generate(yobro);
    for (int i =0 ; i < origin.size(); i++) {
        cout << std::bitset<8>(yobro[i]) << "\n";
    }

    cout << duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - a).count() << " μs\n";
}
