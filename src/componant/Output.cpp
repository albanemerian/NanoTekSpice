/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Output
*/


#include "Output.hpp"

nts::Output::Output(std::string const &value) {
    _pins[1]._name = value;
    _pins[1]._type = "output";
    _pins[1]._value = nts::Tristate::Undefined;
    MAX_PIN = 1;
}

nts::Output::~Output() {}

size_t nts::Output::getMaxPin() const {

    return 1;
}

std::string nts::Output::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Output::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::Output::getPrevValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Output::compute(std::size_t pin) {
    if (pin == 1) {
        return getPinState(pin);
    }
    return nts::Tristate::Undefined;
}

void nts::Output::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}


nts::Tristate nts::Output::getNextValue() const {
    return nts::Tristate::Undefined;
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

void nts::Output::simulate(std::size_t tick) {
    (void)tick;
}
