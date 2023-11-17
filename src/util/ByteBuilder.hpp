#ifndef VALENTINEASSEMBLER_BYTEBUILDER_HPP
#define VALENTINEASSEMBLER_BYTEBUILDER_HPP

#include <cstdint>
#include <cstdlib>
#include <string>
#include <bitset>
#include <cmath>

typedef uint8_t byte;

template<std::size_t SIZE>
struct Block {
    byte block[SIZE] = {0};

    operator std::string() {
        std::string build;
        for (unsigned long i = 0; i < SIZE; i++) {
            build += std::bitset<8>(block[i]).to_string() + " ";
        }
        return build;
    }
};

struct Bits {
    const byte value;
    const byte size;
};

template<std::size_t SIZE>
class ByteBuilder {
private:
    Block<SIZE> block;
    byte bit = 0;
public:
    ByteBuilder()=default;
    void get (byte* ptr);
    std::string getBlock() {
        return block;
    }

    void nextByte();
    void operator+= (byte bit_) {
        this->bit += bit_;
    }
    void operator+= (const Bits& set) {
        const byte rem = 8 - ((bit) % 8);   /* subtract overlap, see how many extra bytes exist. */
        const byte offset = -(rem - 8);
        const bool multiByte = (set.size > rem);
        const byte iter = multiByte ? (set.size - rem / 8) + 2 : 1;
        for (int i = 0; i < iter ; i++) {
            if (bit % 8 != 0) { // first iter
                block.block[bit / 8] |= ((set.value & (byte) std::pow(2, rem) - 1) << offset);
                if (multiByte) {
                    bit += rem;
                } else {
                    bit += set.size;
                }
            } else {
                block.block[bit / 8] |= set.value & (((byte) std::pow(2, set.size) - 1));
                if (multiByte && i == 0) {
                    bit += rem;
                } else {
                    bit += (iter - i == 1) ? (set.size - (rem * std::min(1, i)) - i * 8) : 8;
                }
            }
        }
    }
};

#endif //VALENTINEASSEMBLER_BYTEBUILDER_HPP
