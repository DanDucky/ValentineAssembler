#include <iostream>
#include <string>
#include <chrono>

#include "instructions/include/InstructionLibrary.hpp"
#include "util/Subroutine.hpp"
#include "preprocessor/Preprocessor.hpp"
#include "util/Program.hpp"

using namespace std;

void test() {
    ByteBuilder<3> builder;
    builder += {0xFFFF, 16};
    uint8_t help[3] = {0};
    builder.put(help);
}

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    test();

    Program program(parser); // from InstructionLibrary.hpp
    ifstream file = std::ifstream("/home/danducky/Programming/C++/ValentineAssembler/docs/test/basic.val");
    program.process(file);
    file.close();
    uint8_t out[program.size()];
    program.compile(out);

    cout << duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - a).count() << " μs\n";
}
