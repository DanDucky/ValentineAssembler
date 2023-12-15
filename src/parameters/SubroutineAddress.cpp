#include "SubroutineAddress.hpp"
#include "../processors/Compiler.hpp"

SubroutineAddress::SubroutineAddress(std::string &parameter) {
    Compiler::addresses.insert({parameter, {}});
    auto address = Compiler::addresses.find(parameter);
    refAddress = &address->second;
}

Bits SubroutineAddress::getBits() {
    return {static_cast<uint16_t>(refAddress->address()), 16};
}
