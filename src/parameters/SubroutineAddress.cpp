#include "SubroutineAddress.hpp"
#include "../util/Program.hpp"

SubroutineAddress::SubroutineAddress(std::string &parameter) {
    Program::addresses.insert({parameter, {}});
    auto address = Program::addresses.find(parameter);
    refAddress = &address->second;
}

Bits SubroutineAddress::getBits() {
    return {static_cast<uint16_t>(refAddress->address()), 16};
}
