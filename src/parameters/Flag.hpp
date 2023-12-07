#ifndef VALENTINEASSEMBLER_FLAG_HPP
#define VALENTINEASSEMBLER_FLAG_HPP

#include <map>

#include "include/Parameter.hpp"

#define flagVals(flag) {#flag, flag}

class Flag extends public Parameter {
private:
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

    const static FlagTable flags;

    const FlagID flag;
public:
    paramConstructor(Flag);
    paramDestructor(Flag);

    Bits getBits() override;
};


#endif //VALENTINEASSEMBLER_FLAG_HPP
