#include "Register.hpp"

Register::Register(std::string &parameter) : regID(lookup.find(parameter)->second) {}

Bits Register::getBits() {
    return {regID, 3};
}
