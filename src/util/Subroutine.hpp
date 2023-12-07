#ifndef VALENTINEASSEMBLER_SUBROUTINE_HPP
#define VALENTINEASSEMBLER_SUBROUTINE_HPP

#include <vector>
#include <optional>
#include "../instructions/include/Instruction.hpp"
#include "Address.hpp"

#define SUBROUTINE_PREFIX '.'

class Subroutine {
private:
    std::vector<Instruction*> instructions;
    std::optional<Address> fixedOffset;
public:
    Subroutine()=default;
    explicit Subroutine (Address address);
    ~Subroutine();

    Subroutine* addInstruction(Instruction* instruction);

    Subroutine* setOffset(Address address);

    bool isFixed ();

    [[nodiscard]] Address getOffset () const;

    size_t size ();

    void generate(byte * output);
};

#endif //VALENTINEASSEMBLER_SUBROUTINE_HPP
