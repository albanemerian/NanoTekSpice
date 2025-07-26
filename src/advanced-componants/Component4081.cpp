/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4081
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "Component4081.hpp"
#include "../logic/logic.hpp"
#include "../componant/And.hpp"


nts::Component4081::Component4081(std::string const &value,
    ComponentFactory &factory) : _factory(factory), and1("and1"), and2("and2"), and3("and3"), and4("and4") {
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
    _pins[10] = {"output10", "output", nts::Tristate::Undefined};
    _pins[11] = {"output11", "output", nts::Tristate::Undefined};
    _pins[7] = {"Ignored", "input", nts::Tristate::Undefined};
    _pins[14] = {"Ignored", "input", nts::Tristate::Undefined};
}

nts::Component4081::~Component4081() {}

nts::Tristate nts::Component4081::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

size_t nts::Component4081::getMaxPin() const {
    return 14;
}

void nts::Component4081::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

std::string nts::Component4081::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4081::setPinState(std::size_t pin, nts::Tristate state) {

    _pins[pin]._value = state;
    if (_pins[pin]._type == "output") {
        return;
    }
    simulate(0);
}



void nts::Component4081::simulate(std::size_t tick) {
    and1.setPinState(1, getPinState(1));
    and1.setPinState(2, getPinState(2));
    _pins[3]._value = and1.computes(1, 2, 3);

    and2.setPinState(1, getPinState(5));
    and2.setPinState(2, getPinState(6));
    _pins[4]._value = and2.computes(1, 2, 3);

    and3.setPinState(1, getPinState(8));
    and3.setPinState(2, getPinState(9));
    _pins[10]._value = and3.computes(1, 2, 3);

    and4.setPinState(1, getPinState(12));
    and4.setPinState(2, getPinState(13));
    _pins[11]._value = and4.computes(1, 2, 3);

    (void)tick;
}

nts::Tristate nts::Component4081::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
