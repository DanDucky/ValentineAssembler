#ifndef VALENTINEASSEMBLER_SUBROUTINE_HPP
#define VALENTINEASSEMBLER_SUBROUTINE_HPP

#include <vector>
#include <optional>
#include "../instructions/Instruction.hpp"
#include "../util/Address.hpp"

class Subroutine {
private:
    std::vector<Instruction*> instructions;
    std::optional<size_t> fixedOffset;
public:
    Subroutine() {}
    explicit Subroutine (Address address);
    ~Subroutine();

    Subroutine* addInstruction(Instruction* instruction);

    Subroutine* setOffset(Address address);

    bool isFixed ();

    size_t getOffset () const;

    size_t size ();

    void generate(byte * output);
};

#endif //VALENTINEASSEMBLER_SUBROUTINE_HPP
