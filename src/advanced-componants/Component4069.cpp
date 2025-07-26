/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4069
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "Component4069.hpp"
#include "../logic/logic.hpp"

nts::Component4069::Component4069(std::string const &value, ComponentFactory &factory)
    : _factory(factory), not1("not1"), not2("not2"), not3("not3"), not4("not4"), not5("not5"), not6("not6") {
    _name = value;
    MAX_PIN = 14;

    _pins[1] = {"input1", "input", nts::Tristate::Undefined};
    _pins[3] = {"input2", "input", nts::Tristate::Undefined};
    _pins[5] = {"input3", "input", nts::Tristate::Undefined};
    _pins[9] = {"input4", "input", nts::Tristate::Undefined};
    _pins[11] = {"input5", "input", nts::Tristate::Undefined};
    _pins[13] = {"input6", "input", nts::Tristate::Undefined};

    //output
    _pins[2] = {"output1", "output", nts::Tristate::Undefined};
    _pins[4] = {"output2", "output", nts::Tristate::Undefined};
    _pins[6] = {"output3", "output", nts::Tristate::Undefined};
    _pins[8] = {"output4", "output", nts::Tristate::Undefined};
    _pins[10] = {"output5", "output", nts::Tristate::Undefined};
    _pins[12] = {"output6", "output", nts::Tristate::Undefined};

    _pins[7] = {"Ignored", "input", nts::Tristate::Undefined};
    _pins[14] = {"Ignored", "input", nts::Tristate::Undefined};
}

nts::Component4069::~Component4069() {}

size_t nts::Component4069::getMaxPin() const {
    return 14;
}

std::string nts::Component4069::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4069::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4069::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4069::simulate(std::size_t tick) {
    not1.setPinState(1, getPinState(1));
    _pins[2]._value = not1.computes(1, 2);

    not2.setPinState(1, getPinState(3));
    _pins[4]._value = not2.computes(1, 2);

    not3.setPinState(1, getPinState(5));
    _pins[6]._value = not3.computes(1, 2);

    not4.setPinState(1, getPinState(9));
    _pins[8]._value = not4.computes(1, 2);

    not5.setPinState(1, getPinState(11));
    _pins[10]._value = not5.computes(1, 2);

    not6.setPinState(1, getPinState(13));
    _pins[12]._value = not6.computes(1, 2);
}

nts::Tristate nts::Component4069::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
