cmake_minimum_required(VERSION 3.27)
project(ValentineAssembler)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(ValentineAssembler src/main.cpp src/instructions/include/Instruction.hpp src/instructions/MOV.cpp src/instructions/MOV.hpp src/instructions/BRA.cpp src/instructions/BRA.hpp src/instructions/include/InstructionLibrary.hpp src/parsing/Subroutine.hpp src/util/Address.cpp src/util/Address.hpp src/parsing/Register.cpp src/parsing/Register.hpp src/parsing/Subroutine.cpp src/preprocessor/Preprocessor.cpp src/preprocessor/Preprocessor.hpp src/util/templates/ByteBuilder.hpp src/parsing/Parser.cpp src/parsing/Parser.hpp src/instructions/settings/opcodes.hpp src/instructions/settings/sizes.hpp src/instructions/LOD.cpp src/instructions/LOD.hpp src/instructions/LOD.cpp src/util/Program.cpp src/util/Program.hpp)
