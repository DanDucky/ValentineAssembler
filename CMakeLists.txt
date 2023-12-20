cmake_minimum_required(VERSION 3.24)
project(ValentineAssembler)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(ValentineAssembler src/main.cpp src/instructions/include/Instruction.hpp src/instructions/MOV.cpp src/instructions/MOV.hpp src/instructions/BRA.cpp src/instructions/BRA.hpp src/instructions/include/InstructionLibrary.hpp src/util/Subroutine.hpp src/util/Address.cpp src/util/Address.hpp src/parameters/Register.cpp src/parameters/Register.hpp src/util/Subroutine.cpp src/processors/Preprocessor.cpp src/processors/Preprocessor.hpp src/util/templates/ByteBuilder.hpp src/util/Parser.cpp src/util/Parser.hpp src/instructions/settings/opcodes.hpp src/instructions/settings/sizes.hpp src/instructions/LOD.cpp src/instructions/LOD.hpp src/instructions/LOD.cpp src/processors/Compiler.cpp src/processors/Compiler.hpp src/parameters/Value.cpp src/parameters/Value.hpp src/parameters/include/Parameter.hpp src/parameters/Flag.cpp src/parameters/Flag.hpp src/parameters/SubroutineAddress.cpp src/parameters/SubroutineAddress.hpp src/instructions/JMP.cpp src/instructions/JMP.hpp src/util/DerivedConcept.hpp src/parameters/include/ParameterLibrary.hpp src/instructions/ADD.cpp src/instructions/ADD.hpp src/instructions/CMP.cpp src/instructions/CMP.hpp src/util/Binary.cpp src/util/Binary.hpp src/instructions/STR.cpp src/instructions/STR.hpp src/util/Printer.cpp src/util/Printer.hpp)

target_link_libraries(ValentineAssembler m stdc++)
