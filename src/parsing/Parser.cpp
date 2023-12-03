#include <algorithm>
#include <iostream>

#include "Parser.hpp"

using namespace std;

void Parser::splitByPrefixes(std::string &in, Parameter** out,const size_t size) {
    auto lastIndex = findNextPrefix(in, 0);

    for (unsigned int i = 0; i < size; i++) {
        const auto next = findNextPrefix(in, lastIndex+1);
        auto args = string(&in[lastIndex + 1], &in[next != std::string::npos ? next : in.size()]);
        const auto parameter = parameterTable.find(in[lastIndex]);
        if (parameter != parameterTable.end()) {
            out[i] = parameter->second(args);
        }
        lastIndex = next;
    }
}

size_t Parser::findNextPrefix(string &str, size_t start) {
    size_t out = std::string::npos;
    for (const auto& prefix : parameterTable) {
        out = std::min(str.find(prefix.first, start), out); // npos is 0xFFFF... so I don't think this will fail
    }
    return out;
}

size_t Parser::numberOfPrefixes(string &str) {
    auto const prefix = [] (char ch) -> bool {
        return parameterTable.find(ch) != parameterTable.end();
    };

    return std::ranges::count_if(str, prefix);
}
