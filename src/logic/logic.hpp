/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** logic
*/

#ifndef LOGIC_HPP_
#define LOGIC_HPP_

#include <iostream>
#include "../AComponent.hpp"

namespace nts {

Tristate And_logic(nts::Tristate pin1, nts::Tristate pin2, size_t out);
Tristate Or_logic(nts::Tristate pin1, nts::Tristate pin2, size_t out);
Tristate Clock_logic(nts::Tristate pin1, size_t out);
Tristate Xor_logic(nts::Tristate pin1, nts::Tristate pin2, size_t out);
Tristate Nand_logic(nts::Tristate pin1, nts::Tristate pin2, size_t out);
Tristate Nor_logic(nts::Tristate pin1, nts::Tristate pin2, size_t out);
Tristate Not_logic(nts::Tristate pin1, size_t out);
Tristate True_logic(nts::Tristate pin1, size_t out);
Tristate False_logic(nts::Tristate pin1, size_t out);
Tristate Sum_logic(nts::Tristate a, nts::Tristate b, nts::Tristate carryIn, size_t carryOut);
Tristate Carry_logic(nts::Tristate a, nts::Tristate b, nts::Tristate carryIn, size_t carryOut);
Tristate Flipflop_logic(nts::Tristate clkState, nts::Tristate prevClkState, nts::Tristate dState,
    nts::Tristate setState, nts::Tristate resetState, nts::Tristate Qvalue,size_t q, size_t qNot);
// Tristate Flipflop_logic(nts::Tristate clkState, nts::Tristate dState, nts::Tristate setState, nts::Tristate resetState, size_t q, size_t qNot);
Tristate Counter_logic(nts::Tristate c1, nts::Tristate r, size_t q, size_t qNot);
int Selector_logic(nts::Tristate a, nts::Tristate b, nts::Tristate c);
extern std::map<std::size_t, nts::Pin> _pins;

}

#endif /* !LOGIC_HPP_ */
