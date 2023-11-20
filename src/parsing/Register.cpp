#include "Register.hpp"

Register::Register(const std::string &regName) : regID(lookup.find(regName)->second) {}

uint8_t Register::getIndex() const {
    return regID;
}
