/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4013
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "../logic/logic.hpp"
#include "Component4013.hpp"

nts::Component4013::Component4013(std::string const &value,
    ComponentFactory &factory) : _factory(factory), _flipFlop1("flipFlop1"), _flipFlop2("flipFlop2") {

    _name = value;
    MAX_PIN = 14;
    //first flipflop
    _pins[1] = {"out_1_q", "output", nts::Tristate::Undefined};
    _pins[2] = {"out_1_qb", "output", nts::Tristate::Undefined};
    _pins[3] = {"cl_1_clock", "input", nts::Tristate::Undefined};
    _pins[5] = {"in_1_data", "input", nts::Tristate::Undefined};
    _pins[6] = {"in_1_set", "input", nts::Tristate::Undefined};
    _pins[4] = {"in_1_reset", "input", nts::Tristate::Undefined};

    //second flipflop
    _pins[9] = {"in_2_data", "input", nts::Tristate::Undefined};
    _pins[8] = {"in_2_set", "input", nts::Tristate::Undefined};
    _pins[10] = {"in_2_reset", "input", nts::Tristate::Undefined};
    _pins[11] = {"cl_2_clock", "input", nts::Tristate::Undefined};
    _pins[13] = {"out_2_q", "output", nts::Tristate::Undefined};
    _pins[12] = {"out_2_qb", "output", nts::Tristate::Undefined};
}

nts::Component4013::~Component4013() {}

size_t nts::Component4013::getMaxPin() const {
    return 14;
}

void nts::Component4013::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    if (pin == 3) { // Assuming pin 3 is the clock pin
        _linkedClockComponent = &other;
    }
    if (pin == 11) { // Assuming pin 11 is the clock pin
        _linkedClockComponent2 = &other;
    }
    other.setPinState(otherPin, getPinState(pin));
}

std::string nts::Component4013::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Component4013::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4013::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4013::simulate(std::size_t tick) {
    (void)tick;

    if (tick != 0) {
        nts::Tristate clockValue = _linkedClockComponent->getPinState(1);
        _pins[3]._value = clockValue;
        _nextValue = _linkedClockComponent->getPrevValue();

        nts::Tristate newclockValue = _linkedClockComponent2->getPinState(1);
        _pins[11]._value = newclockValue;
        _nextValue2 = _linkedClockComponent2->getPrevValue(); //here not good
    }
    _flipFlop1.setPinState(3, getPinState(3)); // clock
    _flipFlop1.setPinState(5, getPinState(5)); // data
    _flipFlop1.setPinState(6, getPinState(6)); // set
    _flipFlop1.setPinState(4, getPinState(4)); // reset
    _flipFlop1.setPrev(_nextValue);
    _flipFlop1.simulate(tick);
    _pins[1]._value = _flipFlop1.getPinState(1); // Q
    _pins[2]._value = _flipFlop1.getPinState(2); // Q~


    _flipFlop2.setPinState(3, getPinState(11)); // clock
    _flipFlop2.setPinState(5, getPinState(9)); // data
    _flipFlop2.setPinState(6, getPinState(8)); // set
    _flipFlop2.setPinState(4, getPinState(10)); // reset
    _flipFlop2.setPrev(_nextValue2);
    _flipFlop2.simulate(tick);
    _pins[13]._value = _flipFlop2.getPinState(1); // Q
    _pins[12]._value = _flipFlop2.getPinState(2); // Q~
}

nts::Tristate nts::Component4013::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
