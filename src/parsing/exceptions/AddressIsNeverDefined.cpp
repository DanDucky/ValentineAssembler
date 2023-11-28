//
// Created by danducky on 11/26/23.
//

#include "AddressIsNeverDefined.hpp"

#include <utility>

const char *AddressIsNeverDefined::what() const noexcept {
    return exception::what();
}

AddressIsNeverDefined::AddressIsNeverDefined(std::string symbol, std::vector<unsigned int> lines,
                                             AddressIsNeverDefined::Type type) : symbol(std::move(symbol)), lines(std::move(lines)), type(type){
}
