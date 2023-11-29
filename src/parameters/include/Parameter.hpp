#ifndef VALENTINEASSEMBLER_PARAMETER_HPP
#define VALENTINEASSEMBLER_PARAMETER_HPP

#include <string>

#include "../../util/templates/ByteBuilder.hpp"

#define paramConstructor(param)                    \
    explicit param (std::string& parameter)
#define paramDestructor(param) ~param() = default
#define extends :

class Parameter {
public:
    virtual Bits getBits()=0;
    operator const Bits() {
        return getBits();
    };
};

#endif //VALENTINEASSEMBLER_PARAMETER_HPP
