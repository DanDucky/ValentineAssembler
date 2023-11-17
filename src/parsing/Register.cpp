#include "Register.hpp"

Register::Register(const std::string &regName) : regID(lookup.find(regName)->second) {}
