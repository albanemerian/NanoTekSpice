/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** FlipFlop
*/


#include "FlipFlop.hpp"
#include "../logic/logic.hpp"

nts::FlipFlop::FlipFlop(std::string const &value) : _clock("clock") {
    _name = value;

    _pins[3] = {"cl", "clocks", nts::Tristate::Undefined};
    _pins[5] = {"D", "input", nts::Tristate::Undefined};
    _pins[6] = {"set", "input", nts::Tristate::Undefined};
    _pins[4] = {"R", "input", nts::Tristate::Undefined};
    _pins[1] = {"Q", "output", nts::Tristate::Undefined};
    _pins[2] = {"Q~", "output", nts::Tristate::Undefined};
    _prev = nts::Tristate::Undefined;
    MAX_PIN = 6;
}

nts::FlipFlop::~FlipFlop() {}

size_t nts::FlipFlop::getMaxPin() const {
    return 6;
}

nts::Tristate nts::FlipFlop::getPrevValue() const {
    return _prev;
}

void nts::FlipFlop::setPrev(nts::Tristate prev) {
    _prev = prev;
}

std::string nts::FlipFlop::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::FlipFlop::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

nts::Tristate nts::FlipFlop::computes(std::size_t pin1, std::size_t pin2, std::size_t pin3,
    std::size_t pin4, std::size_t out, std::size_t outb) {
    return nts::Flipflop_logic(getPinState(pin1), _prev, getPinState(pin2),
        getPinState(pin3), getPinState(pin4), _pins[1]._value, out, outb);
}

nts::Tristate nts::FlipFlop::compute(std::size_t pin) {
    if (pin != 3)
        return getPinState(pin);
    return computes(3, 5, 6, 4, 1, 2);
}

nts::Tristate nts::FlipFlop::getNextValue() const {
    return _prev;
}

void nts::FlipFlop::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::FlipFlop::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {

    other.setPinState(otherPin, getPinState(pin));
}

void nts::FlipFlop::simulate(std::size_t tick) {
    (void)tick;

    if (tick == 0)
        return;
    nts::Tristate result = compute(3);
    setPinState(1, result);
    if (result == nts::Tristate::Undefined) {
        setPinState(2, nts::Tristate::Undefined);
        return;
    }
    if (_pins[6]._value == nts::Tristate::True && _pins[4]._value == nts::Tristate::True) {
        setPinState(1, nts::Tristate::True);
        setPinState(2, nts::Tristate::True);
        return;
    }
    setPinState(2, (result == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True);
}
