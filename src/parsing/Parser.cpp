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

Address Parser::fixedOffset(string &str) {
    const auto colon = str.find(SEPARATOR);
    return {static_cast<size_t>(std::stoi(string(&str[colon + 1], &str.back() + 1))), 0};
}

void Parser::split(const string &str, std::string *out, size_t splits, char ch) {
    unsigned long last = -1;
    for (int i = 0; i < splits; i++) {
        const auto next = str.find(ch, last + 1);
        out[i] = std::string(&str[last + 1], &str[std::min(str.size(), next)]);
        last = next;
    }
}
