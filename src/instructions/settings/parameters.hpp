#ifndef VALENTINEASSEMBLER_PARAMETERS_HPP
#define VALENTINEASSEMBLER_PARAMETERS_HPP

#define BOR_INTERNAL_PARAMS {0, 4}
#define AND_INTERNAL_PARAMS {1, 4}
#define XOR_INTERNAL_PARAMS {2, 4}
#define NOT_INTERNAL_PARAMS {3, 4}
#define ADD_INTERNAL_PARAMS {4, 4}
#define SUB_INTERNAL_PARAMS {5, 4}
#define ASL_INTERNAL_PARAMS {6, 4}
#define ASR_INTERNAL_PARAMS {7, 4}
#define ROL_INTERNAL_PARAMS {8, 4}
#define ROR_INTERNAL_PARAMS {9, 4}
#define CMP_INTERNAL_PARAMS {10, 4}

#define NOP_INTERNAL_PARAMS {0, 4}
#define STP_INTERNAL_PARAMS {0b01, 4} // store program counter internal
#define STS_INTERNAL_PARAMS {0b11, 4} // store stack ptr internal
#define LDP_INTERNAL_PARAMS {0b00, 4} // load pc
#define LDS_INTERNAL_PARAMS {0b10, 4} // load stackptr

// program           PARAMS
#define BRA_INTERNAL_PARAMS {0, 4} // 3
#define JMP_INTERNAL_PARAMS {1, 4} // 3
#define MPC_INTERNAL_PARAMS {0, 4} // X+Y -> PC
#define LOD_INTERNAL_PARAMS {0, 4} // 2

// memory            PARAMS
#define STR_INTERNAL_PARAMS {0, 4} // 1
#define PUL_INTERNAL_PARAMS {0, 4}
#define PSH_INTERNAL_PARAMS {1, 4}
#define POL_INTERNAL_PARAMS {0, 4}

#define MOV_INTERNAL_PARAMS {0, 4}
#endif //VALENTINEASSEMBLER_PARAMETERS_HPP
