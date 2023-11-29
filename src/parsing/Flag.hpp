#ifndef VALENTINEASSEMBLER_FLAG_HPP
#define VALENTINEASSEMBLER_FLAG_HPP

#include <map>

#include "include/Parameter.hpp"

enum FlagID {
    CMP,
    CRY,
    INT,
    DIN,
    ST1,
    ST2,
    ST3,
    ST4
};

typedef std::map<std::string , FlagID> FlagTable;

#define flagVals(flag) {#flag, flag}

const static FlagTable flags {
    flagVals(CMP),
    flagVals(CRY),
    flagVals(INT),
    flagVals(DIN),
    flagVals(ST1),
    flagVals(ST2),
    flagVals(ST3),
    flagVals(ST4)
};

class Flag extends public Parameter {
private:
    const FlagID flag;
public:
    paramConstructor(Flag);
    paramDestructor(Flag);

    Bits getBits() override;
};


#endif //VALENTINEASSEMBLER_FLAG_HPP
