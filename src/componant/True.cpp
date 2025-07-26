/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** True
*/

#include "True.hpp"

nts::True::True(std::string const &value) {
    _pins[1]._name = value;
    _pins[1]._type = "true";
    _pins[1]._value = nts::Tristate::True;
    MAX_PIN = 1;
}

nts::True::~True() {}

size_t nts::True::getMaxPin() const {
    return 1;
}

nts::Tristate nts::True::getPinState(std::size_t pin) {
    (void)pin;
    return nts::Tristate::True;
}

std::string nts::True::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::True::getPrevValue() const {
    return nts::Tristate::True;
}

nts::Tristate nts::True::compute(std::size_t pin) {
    if (pin == 1) {
        return getPinState(pin);
    }
    return nts::Tristate::Undefined;
}

nts::Tristate nts::True::getNextValue() const {
    return nts::Tristate::True;
}

void nts::True::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
    _pins[pin]._value = nts::Tristate::True;
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

void nts::True::simulate(std::size_t tick) {
    (void)tick;
}
