/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4001
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "Component4001.hpp"
#include "../logic/logic.hpp"
#include "../componant/Nor.hpp"

nts::Component4001::Component4001(std::string const &value,
    ComponentFactory &factory) : _factory(factory), nor1("nor1"), nor2("nor2"), nor3("nor3"), nor4("nor4") {
    _name = value;
    MAX_PIN = 14;
    //input
    _pins[1] = {"input1", "input", nts::Tristate::Undefined};
    _pins[2] = {"input2", "input", nts::Tristate::Undefined};
    _pins[5] = {"input5", "input", nts::Tristate::Undefined};
    _pins[6] = {"input6", "input", nts::Tristate::Undefined};
    _pins[8] = {"input8", "input", nts::Tristate::Undefined};
    _pins[9] = {"input9", "input", nts::Tristate::Undefined};
    _pins[12] = {"input12", "input", nts::Tristate::Undefined};
    _pins[13] = {"input13", "input", nts::Tristate::Undefined};

    //output
    _pins[3] = {"output3", "output", nts::Tristate::Undefined};
    _pins[4] = {"output4", "output", nts::Tristate::Undefined};
    _pins[7] = {"ignored", "input", nts::Tristate::Undefined};
    _pins[10] = {"output10", "output", nts::Tristate::Undefined};
    _pins[11] = {"output11", "output", nts::Tristate::Undefined};
    _pins[14] = {"ignored2", "input", nts::Tristate::Undefined};
}

nts::Component4001::~Component4001() {}

size_t nts::Component4001::getMaxPin() const {
    return 14;
}

void nts::Component4001::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4001::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4001::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

std::string nts::Component4001::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4001::simulate(std::size_t tick) {
    (void)tick;
    nor1.setPinState(1, getPinState(1));
    nor1.setPinState(2, getPinState(2));
    setPinState(3, nor1.computes(1, 2, 3));

    nor2.setPinState(1, getPinState(5));
    nor2.setPinState(2, getPinState(6));
    setPinState(4, nor2.computes(1, 2, 4));

    nor3.setPinState(1, getPinState(8));
    nor3.setPinState(2, getPinState(9));
    setPinState(10, nor3.computes(1, 2, 10));

    nor4.setPinState(1, getPinState(12));
    nor4.setPinState(2, getPinState(13));
    setPinState(11, nor4.computes(1, 2, 11));
}

nts::Tristate nts::Component4001::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
