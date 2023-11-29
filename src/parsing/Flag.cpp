#include "Flag.hpp"

Flag::Flag(std::string &parameter) : flag(flags.find(parameter)->second){

}

Bits Flag::getBits() {
    return {static_cast<uint32_t>(flag), 3};
}
