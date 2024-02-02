#include <filesystem>
#include "Compiler.hpp"
#include "../instructions/include/InlineSubroutineInstruction.hpp"

std::map<std::string, std::optional<Address>> Compiler::addresses;

Compiler::Compiler(const InstructionSet& instructionSet) : instructions(&instructionSet) , passedAddress(nullptr),
                                                           preprocessor(&passedAddress, &filesProcessed,
                                                                        &inlineSubroutines, &inlineInsertion, &fileTrace) {

}

void Compiler::process(const std::filesystem::path &fileName) {
    filesProcessed.push_back(fileName.filename().string());
    fileTrace.emplace(fileName, std::ifstream(fileName));
    std::string line;
    unsigned int lineNum = 0;
    unsigned int innerMacroLineNum = 0;
    Subroutine* currentSubroutine;
    std::vector<Subroutine*> dynamicSubroutines;
    std::vector<Subroutine*> fixedSubroutines;
    printer = new Printer(countLines(fileTrace.top().second));
    begin = std::chrono::high_resolution_clock::now();
    while (!fileTrace.empty()) {
        if (fileTrace.top().second.eof()) {
            fileTrace.top().second.close();
            fileTrace.pop();
            continue;
        }
        auto timer = std::chrono::high_resolution_clock::now();
        if (!inlineInsertion.has_value()) {
            if (fileTrace.size() == 1) lineNum++;
            innerMacroLineNum = 0;
            getline(fileTrace.top().second, line);
        } else {
            Instruction* inlineFunction = new InlineSubroutineInstruction(inlineInsertion.value());
            if (currentSubroutine->numberOfInstructions() == 0) inlineFunction->setReferenced(passedAddress);
            currentSubroutine->addInstruction(inlineFunction);
            inlineInsertion.reset();
            continue;
        }

        if (preprocessor.processLine(line) == PROGRAM) {
            if (line.starts_with(SUBROUTINE_PREFIX) || line.starts_with(INLINE_SUBROUTINE_PREFIX)) { // new subroutine
                currentSubroutine = new Subroutine(line.starts_with(INLINE_SUBROUTINE_PREFIX));
                if (line.contains(SEPARATOR) && !currentSubroutine->getIsInline()) {
                    currentSubroutine->setOffset(Parser::fixedOffset(line));
                }

                if (currentSubroutine->isFixed()) {
                    fixedSubroutines.push_back(currentSubroutine);
                } else if (!currentSubroutine->getIsInline()){
                    dynamicSubroutines.push_back(currentSubroutine);
                }

                const std::string subroutineName = line.substr(1, line.find(SEPARATOR) - 1);

                if (!currentSubroutine->getIsInline()) {
                    Compiler::addresses.insert({
                                                       subroutineName,
                                                       {}
                                               }); // remember to set this later!!!
                    passedAddress = &Compiler::addresses.find(subroutineName)->second;
                } else { // inline subroutine
                    inlineSubroutines.insert({subroutineName, currentSubroutine});
                }

                printer.value()->printSubroutine(subroutineName, lineNum);
            } else {
                const auto constructor = instructions->find(line.substr(0, 3));
                if (constructor != instructions->end()) { // instruction exists
                    const size_t size = Parser::numberOfPrefixes(line);
                    Parameter* params[size];
                    Parser::getParameters(line, params, size);
                    Instruction* instruction = constructor->second.first(&params[0]);
                    currentSubroutine->addInstruction(instruction);

                    if (line.contains(GET_ADDRESS_PREFIX) || (currentSubroutine->numberOfInstructions() == 1 && !currentSubroutine->getIsInline())) { // if saving address or if it's the first instruction of a subroutine
                        instruction->setReferenced(passedAddress);
                    }

                    printer.value()->printInstruction(line, instruction, {lineNum, innerMacroLineNum}, timeSince(timer));

                    for (unsigned short i = 0; i < size; i++) { // bruh windows does NOT like range based for loops
                        delete params[i]; // cringe
                    }
                }
            }
        }
    }

    if (!fixedSubroutines.empty()) {
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

        size_t startingPoint = fixedSubroutines.back()->size() + fixedSubroutines.back()->getOffset();

        processed = fixedSubroutines;

        for (const auto& subroutine : dynamicSubroutines) { // lock positions
            subroutine->setOffset(Address::addressFromOffset(startingPoint));
            startingPoint += subroutine->size();

            processed.push_back(subroutine);
        }

        for (const auto& subroutine : processed) { // assign references
            subroutine->assignReferences();
        }

/*
        std::vector<std::pair<size_t, size_t>> freeBlocks; // pair<offset, size>
        freeBlocks.emplace_back(0, fixedSubroutines[0]->getOffset());

        for (int i = 1; i < fixedSubroutines.size(); i++) {
            const auto begin = fixedSubroutines[i - 1]->getOffset() + fixedSubroutines[i - 1]->size() + 1;
            // todo make sure this doesn't become negative :3
            freeBlocks.emplace_back(begin, fixedSubroutines[i]->getOffset() - begin);
        }
        const auto lastIter = std::remove_if(freeBlocks.begin(), freeBlocks.end(),
                                             [] (std::pair<size_t, size_t> element) -> bool {
                                                 const size_t second = element.second;
                                                 if (second == 0) return true;
                                                 return false;
                                             });
        freeBlocks.erase(lastIter, freeBlocks.end()); // remove all "free" spaces with 0 space

        for (const auto& block : freeBlocks) {

            const size_t numberOfSubroutines = dynamicSubroutines.size();

            size_t possible[numberOfSubroutines + 1][block.second + 1];
            for (int i = 0; i < numberOfSubroutines + 1; i++) {
                for (int j = 0; j < block.second + 1; j++) {
                    possible[i][j] = 0;
                }
            }

            for (int i = 1; i <= numberOfSubroutines; i++) {
                for (int knapsackI = 0; i < block.second; knapsackI++) {
                    if (knapsackI >= i) {
                        possible[i][knapsackI] = std::max(possible[i - 1][knapsackI], dynamicSubroutines[i - 1]->size() + possible[i - 1][knapsackI - 1]);
                    } else {
                        possible[i][knapsackI] = possible[i - 1][knapsackI];
                    }
                }
            }

            std::vector<Subroutine*> out;
            int remainingCapacity = block.second;

            for (int i = numberOfSubroutines; i > 0 && possible[i][remainingCapacity] > 0; i--) {
                if (possible[i][remainingCapacity] != possible[i - 1][remainingCapacity]) {
                    out.push_back(dynamicSubroutines[i - 1]);
                    remainingCapacity -= i;
                }
            }
        }
        */
    }
}

Compiler::~Compiler() {
    for (const auto& subroutine : processed) {
        delete subroutine;
    }
    for (const auto& subroutine : inlineSubroutines) {
        delete subroutine.second;
    }
    if (printer.has_value()) {
        delete printer.value();
    }
}

size_t Compiler::size() {
    size_t size = 0;
    for (const auto& subroutine : processed) {
        size += subroutine->getOffset() - size;
        size += subroutine->size();
    }
    return size;
}

void Compiler::compile(byte *out) {
    size_t size = 0;
    for (const auto& subroutine : processed) {
        size += subroutine->getOffset() - size;

        subroutine->generate(&out[size]);

        size += subroutine->size();
    }
    printer.value()->printStats(&filesProcessed, timeSince(begin));
    printer.value()->printHexDump(out, size);
}

size_t Compiler::countLines(std::ifstream &file) {
    const size_t out = std::count(std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>(), '\n');
    file.seekg(0);
    return out;
}
