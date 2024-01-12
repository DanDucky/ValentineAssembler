#include "Flag.hpp"

const Flag::FlagTable Flag::flags = {
    flagVals(CMP),
    flagVals(CRY),
    flagVals(INT),
    flagVals(DIN),
    flagVals(ST1),
    flagVals(ST2),
    flagVals(ST3),
    flagVals(ST4)
};

Flag::Flag(std::string &parameter) : flag(flags.find(parameter)->second){

}

Bits Flag::getBits() {
    return {static_cast<uint16_t>(flag), 3};
}
