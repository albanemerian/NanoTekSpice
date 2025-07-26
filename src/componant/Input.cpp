/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(std::string const &value) {
    _pins[1]._name = value;
    _pins[1]._type = "input";
    _pins[1]._value = nts::Tristate::Undefined;
    MAX_PIN = 1;
}

nts::Input::~Input() {}

size_t nts::Input::getMaxPin() const {
    return 1;
}

nts::Tristate nts::Input::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}


nts::Tristate nts::Input::getNextValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Input::getPrevValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Input::compute(std::size_t pin) {
    if (pin == 1) {
        return getPinState(pin);
    }
    return nts::Tristate::Undefined;
}

void nts::Input::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

void nts::Input::simulate(std::size_t tick) {
    (void)tick;
}

std::string nts::Input::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}
