#include "Value.hpp"

const Bits Value::getBits() {
    return {value, 8};
}

Value::Value(std::string& parameter) {
    value = std::stoi(parameter);
}
