#include "Address.hpp"

size_t Address::address() const {
    return (page * 256) + offset;
}
