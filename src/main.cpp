#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <chrono>
#include <fstream>

#include "instructions/include/Instruction.hpp"
#include "instructions/include/InstructionLibrary.hpp"
#include "util/Subroutine.hpp"
#include "util/templates/ByteBuilder.hpp"
#include "preprocessor/Preprocessor.hpp"
#include "util/Program.hpp"

using namespace std;

int main() {
//    auto a = std::chrono::high_resolution_clock::now();

    Program program(parser); // from InstructionLibrary.hpp
    ifstream file = std::ifstream("/home/danducky/Programming/C++/ValentineAssembler/docs/test/basic.val");
    program.process(file);
//    Preprocessor processor;
//    string tone = "/MOVER  =  LOD  %  STACK1  $!00001111   ";
//    processor.processLine(tone);
//    string preTest = "\\MOVER";
//    processor.processLine(preTest);
//    auto element = parser.find(string(&preTest[0], &preTest[3]));
//    if (element != parser.end()) {
//        origin.addInstruction(element->second(preTest));
//    }
//    uint8_t yobro[origin.size()];
//    origin.generate(yobro);
//    for (int i =0 ; i < origin.size(); i++) {
//        cout << std::bitset<8>(yobro[i]) << "\n";
//    }
//
//    cout << duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - a).count() << " μs\n";
}
