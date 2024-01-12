#ifndef VALENTINEASSEMBLER_COMPILER_HPP
#define VALENTINEASSEMBLER_COMPILER_HPP

#include <map>
#include <optional>
#include <string>
#include <filesystem>
#include <functional>
#include <fstream>
#include <queue>
#include <algorithm>
#include <stack>
#include <chrono>
#include <cmath>

#include "../util/Printer.hpp"
#include "../util/Parser.hpp"
#include "../util/Address.hpp"
#include "../instructions/include/InstructionLibrary.hpp"
#include "../util/Subroutine.hpp"
#include "../processors/Preprocessor.hpp"
#include "../parameters/include/Parameter.hpp"
#include "../util/Binary.hpp"

#define timeSince(time) std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - time).count()

class Compiler {
private:
    const InstructionSet* instructions;
    std::queue<std::string> insertions;
    std::vector<Subroutine*> processed;
    std::vector<std::string> filesProcessed;
    std::optional<Address>* passedAddress;

    Preprocessor preprocessor;
    std::optional<Printer*> printer = nullptr;

    static size_t countLines(std::ifstream& file);
    typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint;
    TimePoint begin;

public:
    static std::map<std::string, std::optional<Address>> addresses;
    explicit Compiler(const InstructionSet& instructionSet);
    ~Compiler();
    void process(const std::filesystem::path &fileName);
    size_t size ();
    void compile(byte* out);
};

#endif //VALENTINEASSEMBLER_COMPILER_HPP
