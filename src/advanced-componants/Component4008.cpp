/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4008
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "Component4008.hpp"
#include "../logic/logic.hpp"

nts::Component4008::Component4008(std::string const &value,
    ComponentFactory &factory) : _factory(factory), _sum1("sum1"),
    _sum2("sum2"), _sum3("sum3"), _sum4("sum4") {
    _name = value;
    MAX_PIN = 16;

    _pins[15] = {"B4", "input", nts::Tristate::Undefined};
    _pins[1] = {"A4", "input", nts::Tristate::Undefined};
    _pins[13] = {"Out4", "output", nts::Tristate::Undefined};

    _pins[2] = {"B3", "input", nts::Tristate::Undefined};
    _pins[3] = {"A3", "input", nts::Tristate::Undefined};
    _pins[12] = {"Out3", "output", nts::Tristate::Undefined};

    _pins[4] = {"B3", "input", nts::Tristate::Undefined};
    _pins[5] = {"A2", "input", nts::Tristate::Undefined};
    _pins[11] = {"Out2", "output", nts::Tristate::Undefined};

    _pins[6] = {"B2", "input", nts::Tristate::Undefined};
    _pins[7] = {"A1", "input", nts::Tristate::Undefined};
    _pins[9] = {"C", "input", nts::Tristate::Undefined};
    _pins[10] = {"Out0", "output", nts::Tristate::Undefined};

    _pins[14] = {"OutC", "output", nts::Tristate::Undefined};

    _pins[8] = {"Ignored", "input", nts::Tristate::Undefined};
    _pins[16] = {"Ignored", "input", nts::Tristate::Undefined};
}

nts::Component4008::~Component4008() {}

size_t nts::Component4008::getMaxPin() const {
    return 16;
}

void nts::Component4008::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4008::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4008::setPinState(std::size_t pin,
    nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4008::simulate(std::size_t tick) {
    (void)tick;
    nts::Tristate state = nts::Tristate::Undefined;

    _sum1.setPinState(1, getPinState(6));
    _sum1.setPinState(2, getPinState(7));
    _sum1.setPinState(3, getPinState(9));
    setPinState(10, _sum1.compute(3));
    state = _sum1.computes(3);

    _sum2.setPinState(1, getPinState(4));
    _sum2.setPinState(2, getPinState(5));
    _sum2.setPinState(3, state);
    setPinState(11, _sum2.compute(3));
    state = _sum2.computes(3);

    _sum3.setPinState(1, getPinState(2));
    _sum3.setPinState(2, getPinState(3));
    _sum3.setPinState(3, state);
    setPinState(12, _sum3.compute(3));
    state = _sum3.computes(3);

    _sum3.setPinState(1, getPinState(15));
    _sum3.setPinState(2, getPinState(1));
    _sum3.setPinState(3, state);
    setPinState(13, _sum3.compute(3));
    setPinState(14, _sum3.computes(3));
}

std::string nts::Component4008::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Component4008::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
