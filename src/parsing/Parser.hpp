#ifndef VALENTINEASSEMBLER_PARSER_HPP
#define VALENTINEASSEMBLER_PARSER_HPP

#include <vector>
#include <string>

#define REGISTER_PREFIX '%'
#define CONST_PREFIX '$'
#define ADDRESS_PREFIX '#'
#define FLAG_PREFIX '^'

static const std::vector<char> prefixes {
    REGISTER_PREFIX,
    CONST_PREFIX,
    ADDRESS_PREFIX,
    FLAG_PREFIX
};

class Parser {
private:
    static size_t findNextPrefix(std::string& str, size_t start);
public:
    static std::vector<std::string> splitByPrefixes(std::string& in);
};

#endif //VALENTINEASSEMBLER_PARSER_HPP
