#ifndef VALENTINEASSEMBLER_REGISTER_HPP
#define VALENTINEASSEMBLER_REGISTER_HPP

#include <cstdint>
#include <string>
#include <map>

#include "../util/templates/ByteBuilder.hpp"
#include "include/Parameter.hpp"

// REGISTER MAP!!!!
enum RegisterID {
    X,
    Y,
    ACC,
    PC1,
    PC2,
    STACK1,
    STACK2,
    FLAGS
};

#define regVal( instruction ) {#instruction, instruction}

const static std::map<std::string, RegisterID> lookup {
        regVal(X),
        regVal(Y),
        regVal(ACC),
        regVal(PC1),
        regVal(PC2),
        regVal(STACK1),
        regVal(STACK2),
        regVal(FLAGS)
};

class Register extends public Parameter {
private:
    byte regID;
public:
    paramConstructor(Register);
    paramDestructor(Register);

    Bits getBits() override;
};

#endif //VALENTINEASSEMBLER_REGISTER_HPP
