#include "SubroutineAddress.hpp"
#include "../processors/Compiler.hpp"

SubroutineAddress::SubroutineAddress(std::string &parameter) {
    Compiler::addresses.insert({parameter, std::optional<Address>()});
    auto address = Compiler::addresses.find(parameter);
    refAddress = &address->second;
}

Bits SubroutineAddress::getBits() {
    if (!refAddress->has_value()) /* this means that it has not been set yet, and should only be called when rendering output */ {
        return {0xFFFF, 16};
    }
    return {static_cast<uint16_t>(refAddress->value().address()), 16};
}
