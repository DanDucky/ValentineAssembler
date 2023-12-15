#include "Address.hpp"

size_t Address::address() const {
    return (page * 256) + offset;
}

Address Address::addressFromOffset(size_t fromOrigin) {
    return {fromOrigin / 256, fromOrigin % 256};
}
