cmake_minimum_required(VERSION 3.27)
project(ValentineAssembler)

set(CMAKE_CXX_STANDARD 23)

add_executable(ValentineAssembler src/main.cpp src/instructions/Instruction.hpp src/instructions/MOV.cpp src/instructions/MOV.hpp src/instructions/BRA.cpp src/instructions/BRA.hpp src/instructions/InstructionLibrary.hpp)
