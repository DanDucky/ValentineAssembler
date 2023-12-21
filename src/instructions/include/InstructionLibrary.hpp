#ifndef VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
#define VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP

#include "Instruction.hpp"
#include "../MOV.hpp"
#include "../BRA.hpp"
#include "../LOD.hpp"
#include "../JMP.hpp"
#include "../singles/ADD.hpp"
#include "../singles/CMP.hpp"
#include "../STR.hpp"
#include "../singles/STP.hpp"
#include "../singles/BOR.hpp"

#include <string>
#include <functional>

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

typedef std::map<std::string, std::function<Instruction*(Parameter**)>> InstructionSet;

static const InstructionSet parser = {
        vals(MOV),
        vals(BRA),
        vals(LOD),
        vals(JMP),
        vals(STR),

        vals(ADD),
        vals(CMP),
        vals(STP),
        vals(BOR)
};

#endif //VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
