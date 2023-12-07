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

#define SEPARATOR ':'
#define USE_MACRO_PREFIX '\\'
#define DEFINE_MACRO_PREFIX '/'
#define MULTI_LINE '\\'
#define GET_ADDRESS_PREFIX '&'
#define BINARY_PREFIX '!'
#define COMMENT_PREFIX ';'

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
    static void splitByPrefixes(std::string &in, Parameter** out, size_t size);
    static size_t numberOfPrefixes(std::string& str);
    static Address fixedOffset(std::string& str);
    static void split(const std::string &str, std::string *out, size_t splits, char ch);
};

#endif //VALENTINEASSEMBLER_PARSER_HPP
