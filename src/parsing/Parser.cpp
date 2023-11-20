#include <algorithm>
#include <iostream>

#include "Parser.hpp"

using namespace std;

std::vector<std::string> Parser::splitAfter(std::string& in, char ch) {
    vector<string> out;
    auto lastIndex = in.find(ch);

    for (unsigned int i = 0; i < std::ranges::count(in, ch); i++) {
        const auto next = in.find(ch, lastIndex +1);
        out.emplace_back(&in[lastIndex + 1], &in[next != std::string::npos ? next : in.size()]);
        lastIndex = next;
        cout << out.back() << "\n";
    }
    return out;
}
