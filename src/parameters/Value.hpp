#ifndef VALENTINEASSEMBLER_VALUE_HPP
#define VALENTINEASSEMBLER_VALUE_HPP

#include "include/Parameter.hpp"

class Value extends public Parameter {
private:
    byte value;
public:
    Bits getBits() override;

    paramConstructor(Value);
    paramDestructor(Value);
};


#endif //VALENTINEASSEMBLER_VALUE_HPP
