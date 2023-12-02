#ifndef VALENTINEASSEMBLER_DERIVEDCONCEPT_HPP
#define VALENTINEASSEMBLER_DERIVEDCONCEPT_HPP

#include <concepts>

template<class Child, class Base>
concept Derived = std::is_base_of<Base, Child>::value;

#endif //VALENTINEASSEMBLER_DERIVEDCONCEPT_HPP
