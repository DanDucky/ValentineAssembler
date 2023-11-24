#include <algorithm>
#include <iostream>

#include "Parser.hpp"

using namespace std;

std::vector<std::string> Parser::splitByPrefixes(std::string &in) {
    vector<string> out;
    auto lastIndex = findNextPrefix(in, 0);

    auto const prefix = [] (char ch) -> bool {
        return std::find(prefixes.begin(), prefixes.end(), ch) != prefixes.end();
    };

    const auto occurrences = std::ranges::count_if(in, prefix);

    for (unsigned int i = 0; i < occurrences; i++) {
        const auto next = findNextPrefix(in, lastIndex+1);
        out.emplace_back(&in[lastIndex + 1], &in[next != std::string::npos ? next : in.size()]);
        lastIndex = next;
    }
    return out;
}

size_t Parser::findNextPrefix(string &str, size_t start) {
    size_t out = std::string::npos;
    for (char prefix : prefixes) {
        out = std::min(str.find(prefix, start), out); // npos is 0xFFFF... so I don't think this will fail
    }
    return out;
}
