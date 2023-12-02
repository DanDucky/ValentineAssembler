#include "Program.hpp"
#include "../parsing/Parser.hpp"

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
                program.push_back(currentSubroutine);
            } else {
                const auto constructor = instructions->find(line.substr(0, 3));
                if (constructor != instructions->end()) { // instruction exists
                    auto params = Parser::splitByPrefixes(line);
                    currentSubroutine->addInstruction(constructor->second(params));
                    for (const auto& param : params) {
                        delete param;
                    }
                }
            }
        }
    }
}

Program::~Program() {
    for (const auto& routine : program) {
        delete routine;
    }
}
