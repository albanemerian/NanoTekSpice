/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** AndThree
*/

#include "AndThree.hpp"
#include "../logic/logic.hpp"


nts::AndThree::AndThree(std::string const &value) : _Nand("and") {
    _name = value;
    MAX_PIN = 4;
    _pins[1] = {"input1", "input", nts::Tristate::Undefined};
    _pins[2] = {"input2", "input", nts::Tristate::Undefined};
    _pins[3] = {"input3", "input", nts::Tristate::Undefined};
    _pins[4] = {"output", "output", nts::Tristate::Undefined};
}

nts::AndThree::~AndThree() {
}

nts::Tristate nts::AndThree::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::AndThree::getPrevValue() const {
    return nts::Tristate::Undefined;
}

size_t nts::AndThree::getMaxPin() const {
    return 4;
}

void nts::AndThree::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

std::string nts::AndThree::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::AndThree::getNextValue() const {
    return nts::Tristate::Undefined;
}

void nts::AndThree::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}


void nts::AndThree::simulate(std::size_t tick) {
    if (_pins[1]._value == nts::Tristate::False || _pins[2]._value == nts::Tristate::False || _pins[3]._value == nts::Tristate::False) {
        _pins[4]._value = nts::Tristate::True;
    }
    if (_pins[1]._value == nts::Tristate::True && _pins[2]._value == nts::Tristate::True && _pins[3]._value == nts::Tristate::True) {
        _pins[4]._value = nts::Tristate::False;
    }
    _pins[4]._value = nts::Tristate::Undefined;
}

nts::Tristate nts::AndThree::compute(std::size_t pin) {
    if (_pins[1]._value == nts::Tristate::False || _pins[2]._value == nts::Tristate::False || _pins[3]._value == nts::Tristate::False) {
        return nts::Tristate::True;
    }
    if (_pins[1]._value == nts::Tristate::True && _pins[2]._value == nts::Tristate::True && _pins[3]._value == nts::Tristate::True) {
        return nts::Tristate::False;
    }
    return nts::Tristate::Undefined;
}
