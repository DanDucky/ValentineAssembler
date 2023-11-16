#include "Register.hpp"

Register::Register(const std::string &regName) : reg(lookup.find(regName)->second) {}
