#ifndef VALENTINEASSEMBLER_BYTEBUILDER_HPP
#define VALENTINEASSEMBLER_BYTEBUILDER_HPP

#include <cstdint>
#include <cstdlib>
#include <string>
#include <bitset>
#include <cmath>
#include <cstring>

typedef uint8_t byte;

struct Bits {
    const uint32_t value;
    const byte size;
};

template<std::size_t SIZE>
class ByteBuilder {
private:
    std::bitset<SIZE * 8> bitset {0};
    byte bit = 0;
public:
    ByteBuilder()=default;
    void put (byte* ptr);

    void nextByte();
    void operator+= (const Bits& set);
};

template<std::size_t SIZE>
void ByteBuilder<SIZE>::operator+=(const Bits &set) {
    bitset |= (set.value << bit);
    bit += set.size;
}

template<std::size_t SIZE>
void ByteBuilder<SIZE>::nextByte() {
    bit += 8 - bit % 8;
}

template<std::size_t SIZE>
void ByteBuilder<SIZE>::put(byte* ptr) {
    const auto asBytes = bitset.to_ullong();
    memcpy(ptr, &asBytes, SIZE);
}

#endif //VALENTINEASSEMBLER_BYTEBUILDER_HPP
