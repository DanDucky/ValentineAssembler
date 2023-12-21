#include <iostream>
#include <string>
#include <chrono>
#include <filesystem>
#include <cassert>

#include "../include/universalGetopt.hpp"
#include "instructions/include/InstructionLibrary.hpp"
#include "util/Subroutine.hpp"
#include "processors/Preprocessor.hpp"
#include "processors/Compiler.hpp"

#define switch_no_default(args) \
    switch(args)                \
    default:                            \
    if (true) assert("missing switch case"); \
    else // my beloved

using namespace std;

int main(int argc, char** argv) {
    string inputFile;
    string outputFile;

    if (argc == 1) goto noArgs;
    int opt;
    while((opt = uni::getopt(argc, argv, "f:o:")) != -1) {
        switch_no_default(opt) {
            case 'f' :
                inputFile = uni::optarg;
                break;
            case 'o' :
                outputFile = uni::optarg;
                break;
        }
    }
    noArgs:

    if (inputFile.empty()) {
        cout << "please input a file to compile:\n\t";
        cin >> inputFile;
    }

    if (outputFile.empty()) {
        outputFile = inputFile.substr(0, inputFile.find_last_of('.')) + ".o";
    }

    Compiler program(parser); // from InstructionLibrary.hpp
    ifstream file = std::ifstream(inputFile);
    ofstream outFile = std::ofstream(outputFile);
    program.process(file);
    file.close();
    const auto size = program.size();
    uint8_t out[size];
    for (size_t i = 0; i < size; i++) {
        out[i] = 0;
    }
    program.compile(out);

    outFile.write(reinterpret_cast<const char *>(out), size);
    outFile.close();
}
