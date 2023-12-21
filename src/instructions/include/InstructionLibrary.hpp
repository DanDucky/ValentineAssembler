#ifndef VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
#define VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP

#include "Instruction.hpp"
#include "../MOV.hpp"
#include "../BRA.hpp"
#include "../LOD.hpp"
#include "../JMP.hpp"
#include "../PSH.hpp"
#include "../PUL.hpp"
#include "../POL.hpp"
#include "../STR.hpp"

#include "../singles/ADD.hpp"
#include "../singles/CMP.hpp"
#include "../singles/STP.hpp"
#include "../singles/BOR.hpp"
#include "../singles/ASL.hpp"
#include "../singles/LDP.hpp"
#include "../singles/LDS.hpp"
#include "../singles/NOT.hpp"
#include "../singles/ROL.hpp"
#include "../singles/ROR.hpp"
#include "../singles/STS.hpp"
#include "../singles/SUB.hpp"
#include "../singles/XOR.hpp"
#include "../singles/ASR.hpp"

#include <string>
#include <functional>

#define vals( instruction ) {#instruction, {&Instruction::factory<instruction>}}

typedef std::unordered_map<std::string, std::function<Instruction*(Parameter**)>> InstructionSet;

static const InstructionSet parser = {
        vals(MOV),
        vals(BRA),
        vals(LOD),
        vals(JMP),
        vals(STR),
        vals(PSH),
        vals(PUL),
        vals(POL),

        vals(ADD),
        vals(CMP),
        vals(STP),
        vals(BOR),
        vals(ASL),
        vals(ASR),
        vals(LDP),
        vals(LDS),
        vals(NOT),
        vals(ROL),
        vals(ROR),
        vals(STS),
        vals(SUB),
        vals(XOR)
};

#endif //VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
