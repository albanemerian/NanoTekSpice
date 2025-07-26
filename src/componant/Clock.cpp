/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Clock
*/

#include "Clock.hpp"
#include "../logic/logic.hpp"

nts::Clock::Clock(std::string const &value) {
    _pins[1]._name = value;
    _pins[1]._type = "clock";
    _pins[1]._value = nts::Tristate::Undefined;
    _nextValue = nts::Tristate::Undefined; // Initialize next value
    _prevValue = nts::Tristate::Undefined; // Initialize previous value
    MAX_PIN = 1;
}

nts::Clock::~Clock() {}

nts::Tristate nts::Clock::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

size_t nts::Clock::getMaxPin() const {
    return 1;
}

nts::Tristate nts::Clock::compute(std::size_t pin) {
    if (pin == 1) {
        return getPinState(pin);
    }
    return nts::Tristate::Undefined;
}

void nts::Clock::setPinState(std::size_t pin, nts::Tristate state) {
    if (_pins[pin]._type == "output") {
        return;
    }
    if (pin == 1) {
        _pins[pin]._value = state;
        _nextValue = state;
    }
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Clock::getCurrent() {
    return _pins[1]._value;
}

nts::Tristate nts::Clock::getNextValue() const {
    return _nextValue;
}

nts::Tristate nts::Clock::getPrevValue() const {
    return _prevValue;
}

std::string nts::Clock::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Clock::simulate(std::size_t tick) {
    _prevValue = _pins[1]._value;
    _pins[1]._value = _nextValue;
    if (_pins[1]._value == nts::Tristate::True)
        _nextValue = nts::Tristate::False;
    else if (_pins[1]._value == nts::Tristate::False)
        _nextValue = nts::Tristate::True;
    (void)tick;
}

