#ifndef VALENTINEASSEMBLER_PARAMETER_HPP
#define VALENTINEASSEMBLER_PARAMETER_HPP

#include <string>

#include "../../util/templates/ByteBuilder.hpp"
#include "../../util/DerivedConcept.hpp"

#define paramConstructor(param)                    \
    explicit param (std::string& parameter)
#define paramDestructor(param) ~param() = default
#define extends :

class Parameter {
public:
    virtual Bits getBits()=0;
    operator Bits() {
        return getBits();
    };

    template<Derived<Parameter> t>
    static Parameter* factory(std::string& param) {
        return new t(param);
    }
};

#endif //VALENTINEASSEMBLER_PARAMETER_HPP
