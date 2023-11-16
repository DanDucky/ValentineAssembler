cmake_minimum_required(VERSION 3.27)
project(ValentineAssembler)

set(CMAKE_CXX_STANDARD 23)

add_executable(ValentineAssembler src/main.cpp src/instructions/Instruction.hpp src/instructions/MOV.cpp src/instructions/MOV.hpp src/instructions/BRA.cpp src/instructions/BRA.hpp src/instructions/InstructionLibrary.hpp src/parsing/Subroutine.hpp src/util/Address.cpp src/util/Address.hpp src/parsing/Register.cpp src/parsing/Register.hpp src/parsing/Subroutine.cpp src/preprocessor/Preprocessor.cpp src/preprocessor/Preprocessor.hpp)
