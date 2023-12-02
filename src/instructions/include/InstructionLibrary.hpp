#ifndef VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
#define VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP

#include "Instruction.hpp"
#include "../BRA.hpp"
#include "../MOV.hpp"
#include "../LOD.hpp"
#include "../JMP.hpp"

#include <string>
#include <functional>

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

static const std::map<std::string, std::function<Instruction*(std::vector<Parameter*>)>> parser = {
        vals(MOV),
        vals(BRA),
        vals(LOD),
        vals(JMP)
};

#endif //VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
