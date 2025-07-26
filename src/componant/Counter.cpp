/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Counter
*/

#include "Counter.hpp"
#include "../logic/logic.hpp"

nts::Counter::Counter(std::string const &value) {
    _name = value;
    _pins[1] = {"C1", "input", nts::Tristate::Undefined};
    _pins[2] = {"C2", "input", nts::Tristate::Undefined};
    _pins[3] = {"R", "input", nts::Tristate::Undefined};
    _pins[4] = {"Q", "output", nts::Tristate::Undefined};
    _pins[5] = {"Q~", "output", nts::Tristate::Undefined};
    MAX_PIN = 5;
}

nts::Counter::~Counter() {}

size_t nts::Counter::getMaxPin() const {
    return 5;
}

nts::Tristate nts::Counter::getPrevValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Counter::getNextValue() const {
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Counter::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::Counter::computes(std::size_t pin1, std::size_t pin3,
    std::size_t out, std::size_t outb) {
    return nts::Counter_logic(getPinState(pin1), getPinState(pin3), out, outb);
}

nts::Tristate nts::Counter::compute(std::size_t pin) {
    if (pin != 3)
        return getPinState(pin);
    return computes(1, 3, 4, 5);
}

void nts::Counter::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
    if (_pins[pin]._type == "output")
        return;
    nts::Tristate result = compute(3);
    setPinState(4, result);
    setPinState(5, (result == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True);
}

void nts::Counter::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

std::string nts::Counter::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Counter::simulate(std::size_t tick) {
    (void)tick;
    nts::Tristate result = compute(3);
    setPinState(4, result);
    setPinState(5, (result == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True);
}
