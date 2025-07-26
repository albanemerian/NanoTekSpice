/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4011
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "Component4011.hpp"
#include "../logic/logic.hpp"

nts::Component4011::Component4011(std::string const &value,
    ComponentFactory &factory) : _factory(factory), nand1("nand1"), nand2("nand2"),
    nand3("nand3"), nand4("nand4") {
    _name = value;
    MAX_PIN = 14;

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

    _pins[7] = {"ignored", "input", nts::Tristate::Undefined};
    _pins[14] = {"ignored", "input", nts::Tristate::Undefined};
}

nts::Component4011::~Component4011() {}

size_t nts::Component4011::getMaxPin() const {
    return 14;
}

std::string nts::Component4011::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4011::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4011::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4011::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4011::simulate(std::size_t tick) {

    nand1.setPinState(1, getPinState(1));
    nand1.setPinState(2, getPinState(2));
    setPinState(3, nand1.computes(1, 2, 3));

    nand2.setPinState(1, getPinState(5));
    nand2.setPinState(2, getPinState(6));
    setPinState(4, nand2.computes(1, 2, 3));

    nand3.setPinState(1, getPinState(8));
    nand3.setPinState(2, getPinState(9));
    setPinState(10, nand3.computes(1, 2, 3));

    nand4.setPinState(1, getPinState(12));
    nand4.setPinState(2, getPinState(13));
    setPinState(11, nand4.computes(1, 2, 3));
    (void)tick;
}

nts::Tristate nts::Component4011::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
