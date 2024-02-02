#ifndef VALENTINEASSEMBLER_SUBROUTINE_HPP
#define VALENTINEASSEMBLER_SUBROUTINE_HPP

#include <vector>
#include <optional>
#include "../instructions/include/Instruction.hpp"
#include "Address.hpp"

#define SUBROUTINE_PREFIX '.'
#define INLINE_SUBROUTINE_PREFIX '|'

class Subroutine {
private:
    std::vector<Instruction*> instructions;
    std::optional<Address> fixedOffset;
    const bool isInline = false;
public:
    Subroutine()=default;
    explicit Subroutine (Address address);
    explicit Subroutine (bool _isInline) : isInline(_isInline) {

    }
    ~Subroutine();

    Subroutine* addInstruction(Instruction* instruction);

    Subroutine* setOffset(Address address);

    bool isFixed ();

    [[nodiscard]] Address getOffset () const;
    [[nodiscard]] bool getIsInline() const;

    size_t size ();
    size_t numberOfInstructions();

    void generate(byte * output);
    void assignReferences();
};

#endif //VALENTINEASSEMBLER_SUBROUTINE_HPP
