/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** AComponent
*/
#include "AComponent.hpp"

nts::AComponent::AComponent() {}

nts::AComponent::~AComponent() {}

nts::Tristate nts::AComponent::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::AComponent::compute(std::size_t pin) {
    if (_pins[1]._value == nts::Tristate::True && _pins[2]._value == nts::Tristate::True) {
        return nts::Tristate::True;
    } else if (_pins[1]._value == nts::Tristate::False || _pins[2]._value == nts::Tristate::False) {
        return nts::Tristate::False;
    } else {
        return nts::Tristate::Undefined;
    }
    (void)pin;
    return nts::Tristate::Undefined;
}
nts::Tristate nts::AComponent::getNextValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::AComponent::getPrevValue() const {
    return nts::Tristate::Undefined;
}

void nts::AComponent::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setLink(otherPin, *this, pin);
}

void nts::AComponent::simulate(std::size_t tick) {
    (void)tick;
}

size_t nts::AComponent::getMaxPin() const {
    return 1;
}

std::string nts::AComponent::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}
