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

#ifdef _WIN32
#include <windows.h>
#pragma execution_character_set("utf-8")
#endif

#define switch_no_default(args) \
    switch(args)                \
    default:                            \
    if (true) assert("missing switch case"); \
    else // my beloved

using namespace std;

void compileFiles(const std::string& inputFile, const std::string& outputFile) {
    Compiler program(parser); // from InstructionLibrary.hpp
    ofstream outFile = std::ofstream(outputFile);
    program.process(inputFile);
    const auto size = program.size();
    uint8_t out[size];
    for (size_t i = 0; i < size; i++) {
        out[i] = 0;
    }
    program.compile(out);

    outFile.write(reinterpret_cast<const char *>(out), size);
    outFile.close();
}

void getInstructionsTo(const std::string& outputFile) {

}

int main(int argc, char** argv) {

#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    string inputFile;
    string outputFile;

    bool writeInstructions = false;
    bool compile = true;

    if (argc == 1) goto noArgs;
    int opt;
    while((opt = uni::getopt(argc, argv, "f:o:in")) != -1) {
        switch_no_default(opt) {
            case 'f' :
                inputFile = uni::optarg;
                break;
            case 'o' :
                outputFile = uni::optarg;
                break;
            case 'i' :
                writeInstructions = true;
                break;
            case 'n' :
                compile = false;
                break;
        }
    }
    noArgs:

    if (inputFile.empty()) {
        cout << "please input a file to compile or click ENTER to only compile instructions:\n\t";
        std::string input;
        cin >> input;
        if (input.empty()) {
            compile = false;
        } else {
            inputFile = input;
        }
    }

    if (outputFile.empty()) {
        if (inputFile.empty()) {
            cout << "please provide an output file if not compiling from source code\n";
            return 1;
        }
        outputFile = std::filesystem::path(inputFile).parent_path() / std::filesystem::path(inputFile).stem().concat(".o");
    }

    if (compile) {
        compileFiles(inputFile, outputFile);
    }
    if (writeInstructions || !compile) {
        getInstructionsTo(outputFile);
    }
}
