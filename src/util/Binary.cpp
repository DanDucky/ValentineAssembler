#include "Binary.hpp"

std::string Binary::binaryToString(std::uint8_t byte) {
    std::string out(8, '0');
    for (int i = 0; i < 8; i++) {
        out[i] = ((byte << i) & 0b10000000) == 0b10000000 ? '1' : '0';
    }
    return out;
}
