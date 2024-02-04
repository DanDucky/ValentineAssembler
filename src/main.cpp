#include <iostream>
#include <string>
#include <filesystem>
#include <cassert>
#include <optargParser.hpp>

#include "instructions/include/InstructionLibrary.hpp"
#include "util/Subroutine.hpp"
#include "processors/Preprocessor.hpp"
#include "processors/Compiler.hpp"

#ifdef _WIN32
#include <windows.h>
#pragma execution_character_set("utf-8")
#endif

using std::filesystem::path;

#define switch_no_default(args) \
    switch(args)                \
    default:                            \
    if (true) assert("missing switch case"); \
    else // my beloved

using namespace std;

void compileFiles(const path& inputFile, const path& outputFile) {
    Compiler program(parser); // from InstructionLibrary.hpp
    ofstream outFile = std::ofstream(outputFile);
    program.process(inputFile);
    const auto size = program.size();
    uint8_t out[size];
    for (size_t i = 0; i < size; i++) {
        out[i] = 0;
    }
    program.compile(out);

    outFile.write(reinterpret_cast<const char *>(out), (long)size);
    outFile.close();
}

void getInstructionsTo(const path& outputFile) {
    ofstream outFile = std::ofstream(outputFile);
    uint8_t out[256] = {0};
    for (const auto& instruction : parser) {
        const auto opcode = instruction.second.second.opcode;
        for (int i = 0; i < std::pow(2, 8 - opcode.size); i++) {
            out[i << opcode.size | opcode.value] = instruction.second.second.internalOpcode.value | (instruction.second.second.internalParameter.value << 4);
        }
    }
    outFile.write(reinterpret_cast<const char *>(out), 256);
    outFile.close();
}

int main(int argc, char** argv) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    cli::Opt<path, CLI_OPTION_NULL> inputFile("Source File", "input .val source file", "f", "src", "file");
    cli::Opt<path, CLI_OPTION_NULL> outputFile("Binary Output", "output file for flashing to rom", "o", "output");
    cli::Opt<bool, CLI_OPTION_NULL> writeInstructions("Write Instruction Set", "write file for decoder", "i", "instructions");
    cli::Opt<bool, CLI_OPTION_NULL> noCompiler("Turn Off Compiler", "turn off compiler function, normally so you can only execute instruciton set generation", "n", "nc", "c");

    cli::parse(argc, argv, writeInstructions, noCompiler, inputFile, outputFile);

    if (!inputFile.hasValue()) {
        cout << "please input a file to compile or click ENTER to only compile instructions:\n\t";
        std::string input;
        cin >> input;
        if (input.empty()) {
            noCompiler = true;
        } else {
            inputFile = path(input);
        }
    }

    if (!outputFile.hasValue()) {
        if (!inputFile.hasValue()) {
            cout << "please provide an output file if not compiling from source code\n";
            return 1;
        }
        outputFile = ((path)inputFile).parent_path() / std::filesystem::path(inputFile).stem().concat(".o");
    }

    if (!noCompiler) {
        compileFiles(inputFile, outputFile);
    }
    if (writeInstructions || noCompiler) {
        if (!noCompiler) {
            outputFile = ((path)outputFile).parent_path() / std::filesystem::path("INSTRUCTION_DECODER.o");
        }
        getInstructionsTo(outputFile);
    }
}
