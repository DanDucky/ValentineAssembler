#include "SubroutineAddress.hpp"
#include "../util/Program.hpp"

SubroutineAddress::SubroutineAddress(std::string &parameter) {
    auto address = Program::addresses.find(parameter);
    if (address != Program::addresses.end()) { // exists
        refAddress = &address->second;
    } else {
        Program::addresses.insert({parameter, Address()});
    }
}

Bits SubroutineAddress::getBits() {
    return {static_cast<uint32_t>(refAddress->address()), 16};
}
