#ifndef VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
#define VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP

#include "Instruction.hpp"
#include "../BRA.hpp"
#include "../MOV.hpp"
#include "../LOD.hpp"
#include "../JMP.hpp"
#include "../ADD.hpp"

#include <string>
#include <functional>

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

typedef std::map<std::string, std::function<Instruction*(Parameter**)>> InstructionSet;

static const InstructionSet parser = {
        vals(MOV),
        vals(BRA),
        vals(LOD),
        vals(JMP),
        vals(ADD)
};

#endif //VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
