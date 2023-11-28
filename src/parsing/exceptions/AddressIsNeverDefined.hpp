#ifndef VALENTINEASSEMBLER_ADDRESSISNEVERDEFINED_HPP
#define VALENTINEASSEMBLER_ADDRESSISNEVERDEFINED_HPP

#include <exception>
#include <string>
#include <vector>

class AddressIsNeverDefined : public std::exception {
public:
    enum Type {
        SUBROUTINE,
        JUMP
    };
private:
    const std::string symbol;
    const std::vector<unsigned int> lines;
    const Type type;
public:
    AddressIsNeverDefined(std::string symbol, std::vector<unsigned int> lines, Type type);
    [[nodiscard]] const char * what() const noexcept override;
};


#endif //VALENTINEASSEMBLER_ADDRESSISNEVERDEFINED_HPP
