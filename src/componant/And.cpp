/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** And
*/

#include "And.hpp"
#include "../logic/logic.hpp"

nts::And::And(std::string const &value)  {
    _name = value;
    MAX_PIN = 3;
    _pins[1]._name = "input1";
    _pins[1]._type = "input";
    _pins[1]._value = nts::Tristate::Undefined;
    _pins[2]._name = "input2";
    _pins[2]._type = "input";
    _pins[2]._value = nts::Tristate::Undefined;
    _pins[3]._name = "output";
    _pins[3]._type = "output";
    _pins[3]._value = nts::Tristate::Undefined;
}

nts::And::~And() {
}

nts::Tristate nts::And::getPinState(std::size_t pin) {
   return _pins[pin]._value;
}

nts::Tristate nts::And::getPrevValue() const {
    return nts::Tristate::Undefined;
}

size_t nts::And::getMaxPin() const {
    return 3;
}

nts::Tristate nts::And::computes(std::size_t pin1, std::size_t pin2, std::size_t out) {
    return nts::And_logic(getPinState(pin1), getPinState(pin2), out);
}

nts::Tristate nts::And::compute(std::size_t pin) {
    if (pin != 3) {
        return nts::Tristate::Undefined;
    }
    return computes(1, 2, 3);
}

void nts::And::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
    if (_pins[pin]._type == "output") {
        return;
    }
    if (getPinState(1) != nts::Tristate::Undefined && getPinState(2) != nts::Tristate::Undefined) {
        nts::Tristate result = compute(3);
        setPinState(3, result);
    }

}

std::string nts::And::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}


nts::Tristate nts::And::getNextValue() const {
    return nts::Tristate::Undefined;
}

void nts::And::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

void nts::And::simulate(std::size_t tick) {
    (void)tick;
    nts::Tristate result = compute(3);
    setPinState(3, result);
}
