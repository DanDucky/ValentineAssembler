#include "Printer.hpp"

Printer::Printer(size_t file) : leftBufferSize(sizeOfInt(file)){

}

std::string Printer::buffer(size_t size, const std::string &ch) {
    std::string buff;
    for (unsigned int i = 0; i < size; i++) {
        buff += ch;
    }
    return buff;
}

unsigned int Printer::sizeOfInt(unsigned int n) {
    return static_cast<unsigned int>(std::log10(n) + 1);
}

void
Printer::printInstruction(std::string &line, Instruction *instruction, std::pair<size_t, size_t> lineNum, long time) const {
    Parser::addSpaces(line);

//    if (lineNum.second != 0) line.insert(0,std::to_string(lineNum.second) + " " + HORIZONTAL_LINE + RIGHT_ARROW + " ");

    const unsigned int lineBufferSize = std::max(static_cast<size_t>(20), line.size() + 1);

    uint8_t binary[instruction->size()];

    instruction->generate(binary);

    using namespace std;
    cout << "Line " << lineNum.first << buffer(leftBufferSize - sizeOfInt(lineNum.first), " ");
    cout << " " << CROSS << " " << line << " " << buffer(lineBufferSize - line.size(), HORIZONTAL_LINE);
    if (instruction->size() > 1) {
        const auto offset = buffer(5 + leftBufferSize + 1, " ") + VERTICAL_LINE + buffer(2 + lineBufferSize, " ");

        for (int i = 0; i < instruction->size(); i++) {
            if (i == 0) {
                cout << DOWNWARD_CROSS;
            } else if (i + 1 == instruction->size()) {
                cout << offset << BOTTOM_LEFT_CURVE;
            } else {
                cout << offset << RIGHT_CROSS;
            }
            cout << HORIZONTAL_LINE << RIGHT_ARROW << " " << Binary::binaryToString(binary[i]);
            cout << " " << HORIZONTAL_LINE;
            if (i == 0) {
                cout << TOP_RIGHT_CURVE << "\n";
            } else if (i + 1 == instruction->size()) {
                cout << UPWARD_CROSS;
            } else {
                cout << LEFT_CROSS << "\n";
            }
        }
        cout << HORIZONTAL_LINE;
    } else {
        cout << buffer(2, HORIZONTAL_LINE) << RIGHT_ARROW << " " << Binary::binaryToString(binary[0]) << " " << buffer(3, HORIZONTAL_LINE);
    }
    cout << RIGHT_ARROW << " compiled in " << time << " microseconds\n";

}

void Printer::printSubroutine(const std::string &line, size_t lineNum) const {
    using namespace std;
    const unsigned int lineBufferSize = std::max(static_cast<size_t>(20), line.size() + 1);
    cout << buffer(5 + leftBufferSize + 1, " ") << VERTICAL_LINE << "\n";
    cout << "Line " << lineNum << buffer(leftBufferSize - sizeOfInt(lineNum), " ");
    cout << " " << CROSS << " " << line << " ";
    cout << buffer(2 + lineBufferSize - line.size(), HORIZONTAL_LINE);
    cout << RIGHT_ARROW << " ." << line;
    cout << "\n";
}
