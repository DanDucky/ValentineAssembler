#ifndef VALENTINEASSEMBLER_PARSER_HPP
#define VALENTINEASSEMBLER_PARSER_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

#include "../parameters/include/Parameter.hpp"
#include "../parameters/include/ParameterLibrary.hpp"

#define REGISTER_PREFIX '%'
#define CONST_PREFIX '$'
#define ADDRESS_PREFIX '#'
#define FLAG_PREFIX '^'

#define getParam(prefix, param) {prefix, {&Parameter::factory<param>}}

typedef std::map<char, std::function<Parameter*(std::string&)>> ParameterTable;

static const ParameterTable parameterTable = {
        getParam(REGISTER_PREFIX, Register),
        getParam(CONST_PREFIX, Value),
        getParam(ADDRESS_PREFIX, SubroutineAddress),
        getParam(FLAG_PREFIX, Flag)
};

class Parser {
public:
    static size_t findNextPrefix(std::string& str, size_t start);
    static std::vector<Parameter *> splitByPrefixes(std::string& in);
};

#endif //VALENTINEASSEMBLER_PARSER_HPP
