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
    auto a = std::chrono::high_resolution_clock::now();

    Program program(parser); // from InstructionLibrary.hpp
    ifstream file = std::ifstream("/home/danducky/Programming/C++/ValentineAssembler/docs/test/basic.val");
    program.process(file);
    file.close();

    cout << duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - a).count() << " μs\n";
}
