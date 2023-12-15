#ifndef VALENTINEASSEMBLER_ADDRESS_HPP
#define VALENTINEASSEMBLER_ADDRESS_HPP

#include <cstdlib>

struct Address {
    size_t page;
    size_t offset;

    size_t address() const;
    operator size_t() const {
        return address();
    }

    static Address addressFromOffset(size_t fromOrigin);
};


#endif //VALENTINEASSEMBLER_ADDRESS_HPP
