/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4071
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "Component4071.hpp"
#include "../logic/logic.hpp"
#include "../componant/Or.hpp"

nts::Component4071::Component4071(std::string const &value,
    ComponentFactory &factory) : _factory(factory), or1("or1"), or2("or2"), or3("or3"), or4("or4") {
    _name = value;
    MAX_PIN = 14;

    _pins[1] = {"input1", "input", nts::Tristate::Undefined};
    _pins[2] = {"input2", "input", nts::Tristate::Undefined};
    _pins[3] = {"output3", "output", nts::Tristate::Undefined};

    _pins[5] = {"input5", "input", nts::Tristate::Undefined};
    _pins[6] = {"input6", "input", nts::Tristate::Undefined};
    _pins[4] = {"output4", "output", nts::Tristate::Undefined};

    _pins[8] = {"input8", "input", nts::Tristate::Undefined};
    _pins[9] = {"input9", "input", nts::Tristate::Undefined};
    _pins[10] = {"output10", "output", nts::Tristate::Undefined};

    _pins[12] = {"input12", "input", nts::Tristate::Undefined};
    _pins[13] = {"input13", "input", nts::Tristate::Undefined};
    _pins[11] = {"output11", "output", nts::Tristate::Undefined};

    _pins[7] = {"ignored", "input", nts::Tristate::Undefined};
    _pins[14] = {"ignored", "input", nts::Tristate::Undefined};
}

nts::Component4071::~Component4071() {}

size_t nts::Component4071::getMaxPin() const {
    return 14;
}

void nts::Component4071::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

std::string nts::Component4071::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Component4071::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4071::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4071::simulate(std::size_t tick) {
    (void)tick;
    or1.setPinState(1, getPinState(1));
    or1.setPinState(2, getPinState(2));
    _pins[3]._value = or1.computes(1, 2, 3);

    or2.setPinState(1, getPinState(5));
    or2.setPinState(2, getPinState(6));
    setPinState(4, or2.computes(1, 2, 3));
    _pins[4]._value = or2.computes(1, 2, 3);

    or3.setPinState(1, getPinState(8));
    or3.setPinState(2, getPinState(9));
    _pins[10]._value = or3.computes(1, 2, 3);

    or4.setPinState(1, getPinState(12));
    or4.setPinState(2, getPinState(13));
    _pins[11]._value = or4.computes(1, 2, 3);
}

nts::Tristate nts::Component4071::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
