#ifndef VALENTINEASSEMBLER_PARSER_HPP
#define VALENTINEASSEMBLER_PARSER_HPP

#include <vector>
#include <string>

#define REGISTER_PREFIX '%'

class Parser {
public:
    static std::vector<std::string> splitAfter(std::string& in, char ch);
};

#endif //VALENTINEASSEMBLER_PARSER_HPP
