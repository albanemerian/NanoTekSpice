/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Sum
*/

#include "Sum.hpp"
#include "../logic/logic.hpp"

nts::Sum::Sum(std::string const &value) {
    _name = value;
    MAX_PIN = 5;
    _pins[1] = {"input1", "input", nts::Tristate::Undefined};
    _pins[2] = {"input2", "input", nts::Tristate::Undefined};
    _pins[3] = {"carryIn", "input", nts::Tristate::Undefined};
    _pins[4] = {"sum", "output", nts::Tristate::Undefined};
    _pins[5] = {"carryOut", "output", nts::Tristate::Undefined};
}

nts::Sum::~Sum() {}

size_t nts::Sum::getMaxPin() const {
    return 5;
}

std::string nts::Sum::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Sum::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::Sum::getPrevValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Sum::computes(std::size_t pin) {
    if (pin != 3) {
        return nts::Tristate::Undefined;
    }
    return nts::Carry_logic(getPinState(1), getPinState(2), getPinState(3), 5);
}

nts::Tristate nts::Sum::getNextValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Sum::compute(std::size_t pin) {
    if (pin != 3) {
        return nts::Tristate::Undefined;
    }
    return nts::Sum_logic(getPinState(1), getPinState(2), getPinState(3), 4);
}

void nts::Sum::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Sum::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

void nts::Sum::simulate(std::size_t tick) {
    (void)tick;
    setPinState(4, compute(3));
    setPinState(5, computes(3));
}
