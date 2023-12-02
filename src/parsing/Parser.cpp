#include <algorithm>
#include <iostream>

#include "Parser.hpp"

using namespace std;

std::vector<Parameter *> Parser::splitByPrefixes(std::string &in) {
    vector<Parameter*> out;
    auto lastIndex = findNextPrefix(in, 0);

    auto const prefix = [] (char ch) -> bool {
        return parameterTable.find(ch) != parameterTable.end();
    };

    const auto occurrences = std::ranges::count_if(in, prefix);

    for (unsigned int i = 0; i < occurrences; i++) {
        const auto next = findNextPrefix(in, lastIndex+1);
        auto args = string(&in[lastIndex + 1], &in[next != std::string::npos ? next : in.size()]);
        const auto parameter = parameterTable.find(in[lastIndex]);
        if (parameter != parameterTable.end()) {
            out.push_back(parameter->second(args));
        }
        lastIndex = next;
    }
    return out;
}

size_t Parser::findNextPrefix(string &str, size_t start) {
    size_t out = std::string::npos;
    for (const auto& prefix : parameterTable) {
        out = std::min(str.find(prefix.first, start), out); // npos is 0xFFFF... so I don't think this will fail
    }
    return out;
}
