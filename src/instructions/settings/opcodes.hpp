#ifndef VALENTINEASSEMBLER_OPCODES_HPP
#define VALENTINEASSEMBLER_OPCODES_HPP

// arith
#define BOR_OPCODE {0b000010, 6}
#define AND_OPCODE {0b000110, 6}
#define XOR_OPCODE {0b001010, 6}
#define NOT_OPCODE {0b001110, 6}
#define ADD_OPCODE {0b010010, 6}
#define SUB_OPCODE {0b010110, 6}
#define ASL_OPCODE {0b011010, 6}
#define ASR_OPCODE {0b011110, 6}
#define ROL_OPCODE {0b100010, 6}
#define ROR_OPCODE {0b100110, 6}
#define CMP_OPCODE {0b101010, 6}
#define STP_OPCODE {0b101110, 6} // store program counter internal
#define STS_OPCODE {0b110010, 6} // store stack ptr internal
#define LDP_OPCODE {0b110110, 6} // load pc
#define LDS_OPCODE {0b111010, 6} // load stackptr
#define MPC_OPCODE {0b111110, 6} // X+Y -> PC

// program
#define BRA_OPCODE {0b0001, 4} // 3
#define JMP_OPCODE {0b0101, 4} // 3
#define LOD_OPCODE {0b1101, 4} // 2
#define NOP_OPCODE {0b1001, 4} // 1

// memory
#define STR_OPCODE {0b0000, 4} // 1
#define PUL_OPCODE {0b0100, 4}
#define PSH_OPCODE {0b1000, 4}
#define POL_OPCODE {0b1100, 4}

#define MOV_OPCODE {0b11, 2}

#endif //VALENTINEASSEMBLER_OPCODES_HPP
