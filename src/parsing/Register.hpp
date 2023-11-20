#ifndef VALENTINEASSEMBLER_REGISTER_HPP
#define VALENTINEASSEMBLER_REGISTER_HPP

#include <cstdint>
#include <string>
#include <map>

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

#define reg( instruction ) {#instruction, instruction}

const static std::map<std::string, RegisterID> lookup {
        reg(X),
        reg(Y),
        reg(ACC),
        reg(PC1),
        reg(PC2),
        reg(STACK1),
        reg(STACK2),
        reg(FLAGS)
};

class Register {
private:
    uint8_t regID;
public:
    uint8_t getIndex() const;
    Register()=default;
    explicit Register(const std::string& regName);
};

#endif //VALENTINEASSEMBLER_REGISTER_HPP
