/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4512
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "../logic/logic.hpp"
#include "Component4512.hpp"

nts::Component4512::Component4512(std::string const &value, ComponentFactory &factory) : _factory(factory)
{
    _name = value;
    MAX_PIN = 16;
    //input
    _pins[1] = {"X0", "input", nts::Tristate::Undefined};
    _pins[2] = {"X1", "input", nts::Tristate::Undefined};
    _pins[3] = {"X2", "input", nts::Tristate::Undefined};
    _pins[4] = {"X3", "input", nts::Tristate::Undefined};
    _pins[5] = {"X4", "input", nts::Tristate::Undefined};
    _pins[6] = {"X5", "input", nts::Tristate::Undefined};
    _pins[7] = {"X6", "input", nts::Tristate::Undefined};
    _pins[9] = {"X7", "input", nts::Tristate::Undefined};
    _pins[10] = {"Inhibit", "input", nts::Tristate::Undefined};
    _pins[11] = {"A", "input", nts::Tristate::Undefined};
    _pins[12] = {"B", "input", nts::Tristate::Undefined};
    _pins[13] = {"C", "input", nts::Tristate::Undefined};
    _pins[15] = {"OE~", "input", nts::Tristate::Undefined};
    //output
    _pins[14] = {"Z", "output", nts::Tristate::Undefined};
    _pins[8] = {"Empty", "output", nts::Tristate::Undefined};
    _pins[16] = {"Empty", "output", nts::Tristate::Undefined};
}

nts::Component4512::~Component4512() {}

size_t nts::Component4512::getMaxPin() const
{
    return 16;
}

void nts::Component4512::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4512::getPinState(std::size_t pin)
{
    return _pins[pin]._value;
}

void nts::Component4512::setPinState(std::size_t pin, nts::Tristate state)
{
    _pins[pin]._value = state;
}

std::string nts::Component4512::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4512::simulate(std::size_t tick) {
    int res = Selector_logic(getPinState(11), getPinState(12), getPinState(13));

    (void)tick;
    if (getPinState(15) == nts::Tristate::True || res == 0) {
        setPinState(14, nts::Tristate::Undefined);
        return;
    }
    if (getPinState(10) == nts::Tristate::True) {
        setPinState(14, nts::Tristate::False);
        return;
    }
    setPinState(14, getPinState(res));
}

nts::Tristate nts::Component4512::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
