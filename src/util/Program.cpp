#include "Program.hpp"
#include "../parsing/Parser.hpp"
#include <algorithm>

std::map<std::string, Address> Program::addresses;

Program::Program(const InstructionSet& instructionSet) : instructions(&instructionSet) , preprocessor(&insertions) {

}

void Program::process(std::ifstream &stream) {
    if (!stream.is_open()) return;
    std::string line;
    unsigned int lineNum = 0;
    unsigned int innerMacroLineNum = 0;
    Subroutine* currentSubroutine;
    while (!stream.eof()) {
        if (insertions.empty()) {
            lineNum++;
            innerMacroLineNum = 0;
            getline(stream, line);
        } else {
            line = insertions.front();
            insertions.pop();
            innerMacroLineNum++;
        }

        if (preprocessor.processLine(line) == PROGRAM) {
            if (line.starts_with(SUBROUTINE_PREFIX)) { // new subroutine
                currentSubroutine = new Subroutine();
                if (line.contains(SEPARATOR)) {
                    currentSubroutine->setOffset(Parser::fixedOffset(line));
                }

                if (currentSubroutine->isFixed()) {
                    fixedSubroutines.push_back(currentSubroutine);
                } else {
                    program.push_back(currentSubroutine);
                }

                Program::addresses.insert({
                    line.substr(1, line.find(SEPARATOR) - 1),
                    currentSubroutine->isFixed() ? currentSubroutine->getOffset() : Address()
                }); // TODO remember to set this later!!!
            } else {
                const auto constructor = instructions->find(line.substr(0, 3));
                if (constructor != instructions->end()) { // instruction exists
                    const size_t size = Parser::numberOfPrefixes(line);
                    Parameter* params[size];
                    Parser::splitByPrefixes(line, params, size);
                    currentSubroutine->addInstruction(constructor->second(&params[0]));
                    for (unsigned short i = 0; i < size; i++) { // bruh windows does NOT like range based for loops
                        delete params[i]; // cringe
                    }
                }
            }
        }
    }
    // here re-arrange subroutines to best order

    std::qsort(
        fixedSubroutines.data(),
        fixedSubroutines.size(),
        sizeof(Subroutine*),
        [] (const void* x, const void* y) {
            const Subroutine* xSub = *static_cast<Subroutine* const*>(x); // holy shmokes
            const Subroutine* ySub = *static_cast<Subroutine* const*>(y);
            const auto cmp = xSub->getOffset() <=> ySub->getOffset();
            if (cmp < nullptr) {
                return -1;
            } else if (cmp > nullptr) {
                return 1;
            }
            return 0;
        }
    ); // fixed subroutines are now sorted in order!!!
}

Program::~Program() {
    for (const auto& routine : program) {
        delete routine;
    }
}
