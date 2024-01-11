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
    return std::max(static_cast<unsigned int>(std::log10(n) + 1), static_cast<unsigned int>(1));
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

void Printer::printStats(std::vector<std::string> *files, unsigned long time) const {
    using namespace std;
    const unsigned int lineBufferSize = std::max(static_cast<size_t>(20), files->front().size() + 1);
    cout << buffer(5 + leftBufferSize + 1, " ") << VERTICAL_LINE << "\n" << "Trace" << buffer(leftBufferSize + 1, " ") << CROSS << " ";
    cout << files->front();
    if (files->size() > 1) {
        cout << " " << buffer(lineBufferSize - files->front().size(), HORIZONTAL_LINE);
        const auto offset = buffer(5 + leftBufferSize + 1, " ") + VERTICAL_LINE + buffer(2 + lineBufferSize, " ");

        for (int i = 0; i < files->size() - 1; i++) {
            if (i == 0) {
                if (files->size() > 2) cout << DOWNWARD_CROSS;
                else cout << HORIZONTAL_LINE;
            } else if (i + 1 == files->size() - 1) {
                cout << offset << BOTTOM_LEFT_CURVE;
            } else {
                cout << offset << RIGHT_CROSS;
            }
            cout << HORIZONTAL_LINE << RIGHT_ARROW << " " << (*files)[i + 1] << "\n";
        }
    } else {
        cout << "\n";
    }
    cout << buffer(5 + leftBufferSize + 1, " ") << VERTICAL_LINE << "\n" << "Timer" << buffer(leftBufferSize + 1, " ") << CROSS << " " << std::to_string(time) << " μs\n";
}

void Printer::printHexDump(const uint8_t* byteFile, size_t size) const {
    using std::cout;
    cout << buffer(5 + leftBufferSize + 1, " ") << VERTICAL_LINE << "\n" << buffer(5 + leftBufferSize + 1, " ") << RIGHT_CROSS;
    for (int i = 0; i < 8; i++) { // print column labels
        if (i != 0) cout << TOP_LEFT_CURVE;
        cout << " " << i << buffer(3 - sizeOfInt(i), " ");
    }
    cout << "\n" << buffer(5 + leftBufferSize + 1, " ") << RIGHT_CROSS;
    for (int i = 0; i < 8; i++) { // line below column labels
        if (i != 0 && i != 7){
            cout << CROSS;
        } else if (i == 7) {
            cout << LEFT_CROSS;
        }
        if (i != 7) cout << buffer(4, HORIZONTAL_LINE);
    }
    cout << "\n";
    const auto lines = (int)std::ceil((float)size / 8.0f);
    for (size_t i = 0; i < lines; i++) {
        cout << buffer(4 + leftBufferSize + 1 - sizeOfInt(i * 8), " ") << i*8 << " " << CROSS;
        const auto hexesInLine = std::min(static_cast<int>(size - (i*8)), 8);
        for (int indexInLine = 0; indexInLine < hexesInLine; indexInLine++) {
            char hexed[2];
            sprintf(hexed, "%x", byteFile[8*i + indexInLine]);
            if (hexed[1] == '\0') hexed[1] = '0';
            std::reverse(&hexed[0], &hexed[1]);
            cout << " " << hexed << " ";
            if (indexInLine != hexesInLine - 1) {
                if ((i + 1) * 8 + indexInLine > size -2 && i + 1 != lines) {
                    cout << UPWARD_CROSS;
                } else {
                    cout << CROSS;
                }
            }
        }
        if (i == lines -1 ) {
            cout << "\n" << buffer(5 + leftBufferSize +1, " ") << BOTTOM_LEFT_CURVE;
            for (int indexInLine = 0; indexInLine < hexesInLine - 1; indexInLine++) {
                cout << buffer(4, HORIZONTAL_LINE) ;
                if (indexInLine == hexesInLine - 2) {
                    cout << BOTTOM_RIGHT_CURVE;
                } else {
                    cout << UPWARD_CROSS;
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";
}
