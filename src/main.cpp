#include <iostream>
#include <string>
#include <chrono>

#include "instructions/include/InstructionLibrary.hpp"
#include "util/Subroutine.hpp"
#include "processors/Preprocessor.hpp"
#include "processors/Compiler.hpp"

using namespace std;

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    Compiler program(parser); // from InstructionLibrary.hpp
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
