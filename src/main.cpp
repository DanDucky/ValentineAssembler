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
    builder += {0b1001, 4};
    uint8_t help[3] = {0};
    builder.put(help);
}

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    test();

    Program program(parser); // from InstructionLibrary.hpp
    ifstream file = std::ifstream("/home/danducky/Programming/C++/ValentineAssembler/docs/test/basic.val");
    ofstream outFile = std::ofstream("/home/danducky/Programming/C++/ValentineAssembler/docs/test/basic.o");
    program.process(file);
    file.close();
    const auto size = program.size();
    uint8_t out[size];
    for (size_t i = 0; i < size; i++) {
        out[i] = 0;
    }
    program.compile(out);

    outFile.write(reinterpret_cast<const char *>(out), size);

    cout << duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - a).count() << " μs\n";
}
