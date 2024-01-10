#ifndef VALENTINEASSEMBLER_INTERNAL_HPP
#define VALENTINEASSEMBLER_INTERNAL_HPP

//#define READ_REGISTER {0, 3}
//#define PUSH_REGISTER {3, 3}
//#define ALU_SIGNALS {6, 4}

// arith
#define BOR_INTERNAL_OPCODE {1, 4}
#define AND_INTERNAL_OPCODE {1, 4}
#define XOR_INTERNAL_OPCODE {1, 4}
#define NOT_INTERNAL_OPCODE {1, 4}
#define ADD_INTERNAL_OPCODE {1, 4}
#define SUB_INTERNAL_OPCODE {1, 4}
#define ASL_INTERNAL_OPCODE {1, 4}
#define ASR_INTERNAL_OPCODE {1, 4}
#define ROL_INTERNAL_OPCODE {1, 4}
#define ROR_INTERNAL_OPCODE {1, 4}
#define CMP_INTERNAL_OPCODE {1, 4}

#define NOP_INTERNAL_OPCODE {9, 4}
#define STP_INTERNAL_OPCODE {5, 4} // store program counter internal
#define STS_INTERNAL_OPCODE {5, 4} // store stack ptr internal
#define LDP_INTERNAL_OPCODE {5, 4} // load pc
#define LDS_INTERNAL_OPCODE {5, 4} // load stackptr

// program
#define BRA_INTERNAL_OPCODE {6, 4} // 3
#define JMP_INTERNAL_OPCODE {7, 4} // 3
#define LOD_INTERNAL_OPCODE {8, 4} // 2
#define MPC_INTERNAL_OPCODE {7, 4} // X+Y -> PC

// memory
#define STR_INTERNAL_OPCODE {2, 4} // 1
#define PUL_INTERNAL_OPCODE {3, 4}
#define PSH_INTERNAL_OPCODE {4, 4}
#define POL_INTERNAL_OPCODE {4, 4}

#define MOV_INTERNAL_OPCODE {0, 4}

#endif //VALENTINEASSEMBLER_INTERNAL_HPP
