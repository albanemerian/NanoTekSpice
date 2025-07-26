/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Not
*/

#include "Not.hpp"
#include "../logic/logic.hpp"

nts::Not::Not(std::string const &value) {
    _name = value;
    MAX_PIN = 2;
    _pins[1]._name = "input";
    _pins[1]._type = "input";
    _pins[1]._value = nts::Tristate::Undefined;
    _pins[2]._name = "output";
    _pins[2]._type = "output";
    _pins[2]._value = nts::Tristate::Undefined;
}

nts::Not::~Not() {}

size_t nts::Not::getMaxPin() const {
    return 3;
}

nts::Tristate nts::Not::getNextValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Not::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::Not::getPrevValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Not::computes(std::size_t pin1, std::size_t out) {
    return nts::Not_logic(getPinState(pin1), out);
}

nts::Tristate nts::Not::compute(std::size_t pin) {
    if (pin != 2) {
        return nts::Tristate::Undefined;
    }
    return computes(1, 2);
}

void nts::Not::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
    if (_pins[pin]._type == "output") {
        return;
    }
    if (getPinState(1) != nts::Tristate::Undefined) {
        nts::Tristate result = compute(2);
        setPinState(2, result);
    }
}

void nts::Not::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

void nts::Not::simulate(std::size_t tick) {
    if (getPinState(1) != nts::Tristate::Undefined) {
        nts::Tristate result = compute(2);
        setPinState(2, result);
    }
    (void)tick;
}


std::string nts::Not::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}
