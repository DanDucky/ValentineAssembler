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

#define vals( instruction ) {#instruction, instruction}

const static std::map<std::string, RegisterID> lookup {
        vals(X),
        vals(Y),
        vals(ACC),
        vals(PC1),
        vals(PC2),
        vals(STACK1),
        vals(STACK2),
        vals(FLAGS)
};

class Register {
private:
    const uint8_t reg;
public:
    explicit Register(const std::string& regName);
};

#endif //VALENTINEASSEMBLER_REGISTER_HPP
