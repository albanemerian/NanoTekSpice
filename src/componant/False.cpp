/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** False
*/

#include "False.hpp"

nts::False::False(std::string const &value) {
    _pins[1]._name = value;
    _pins[1]._type = "false";
    _pins[1]._value = nts::Tristate::False;
    MAX_PIN = 1;
}

nts::False::~False() {}

size_t nts::False::getMaxPin() const {
    return 1;
}

nts::Tristate nts::False::getPinState(std::size_t pin) {
    (void)pin;
    return nts::Tristate::False;
}

nts::Tristate nts::False::getPrevValue() const {
    return nts::Tristate::False;
}

nts::Tristate nts::False::compute(std::size_t pin) {
    if (pin == 1) {
        return getPinState(pin);
    }
    return nts::Tristate::Undefined;
}


nts::Tristate nts::False::getNextValue() const {
    return nts::Tristate::False;
}

void nts::False::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
    _pins[pin]._value = nts::Tristate::False;
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

std::string nts::False::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::False::simulate(std::size_t tick) {
    (void)tick;
}
