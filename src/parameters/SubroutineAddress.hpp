#ifndef VALENTINEASSEMBLER_SUBROUTINEADDRESS_HPP
#define VALENTINEASSEMBLER_SUBROUTINEADDRESS_HPP

#include "include/Parameter.hpp"
#include "../util/Address.hpp"
#include <optional>

class SubroutineAddress extends public Parameter {
private:
    std::optional<Address>* refAddress; // so this points to a place in a map stored in the processors or program which
                         // maps the name of certain address to their address value. By the time the program
                         // is converted to binary (compiled) the address will be filled into the currently
                         // void location in this map, so when SubroutineAddress is constructed refAddress
                         // might point to some random data but it will eventually point to the correct address
                         // when the order of the program is established (size offsets and such)
public:
    paramConstructor(SubroutineAddress);
    paramDestructor(SubroutineAddress);

    Bits getBits() override;
};

#endif //VALENTINEASSEMBLER_SUBROUTINEADDRESS_HPP
