#ifndef VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
#define VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP

#include "Instruction.hpp"

#include "../settings/internal.hpp"
#include "../settings/parameters.hpp"

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
#include "../singles/MPC.hpp"
#include "../singles/NOP.hpp"

#include <string>
#include <functional>

#define vals( instruction ) {#instruction, {{&Instruction::factory<instruction>}, {instruction##_OPCODE, instruction##_INTERNAL_OPCODE , instruction##_INTERNAL_PARAMS}}}

struct OpcodeInformation {
    const Bits opcode;
    const Bits internalOpcode;
    const Bits internalParameter;
};

typedef std::unordered_map<std::string, const std::pair<std::function<Instruction*(Parameter**)>, const OpcodeInformation>> InstructionSet;

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
        vals(XOR),
        vals(MPC),
        vals(NOP)
};

#endif //VALENTINEASSEMBLER_INSTRUCTIONLIBRARY_HPP
