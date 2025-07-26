/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4040
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "../logic/logic.hpp"
#include "Component4040.hpp"

nts::Component4040::Component4040(std::string const &value,
    ComponentFactory &factory) : _factory(factory) {

    _name = value;
    MAX_PIN = 16;
    _previousClock = nts::Tristate::Undefined;
    counter = 0;

    _pins[10] = {"clock", "input", nts::Tristate::Undefined};
    _pins[11] = {"reset", "input", nts::Tristate::Undefined};

    _pins[9] = {"output0", "output", nts::Tristate::Undefined};
    _pins[7] = {"output1", "output", nts::Tristate::Undefined};
    _pins[6] = {"output2", "output", nts::Tristate::Undefined};
    _pins[5] = {"output3", "output", nts::Tristate::Undefined};
    _pins[3] = {"output4", "output", nts::Tristate::Undefined};
    _pins[2] = {"output5", "output", nts::Tristate::Undefined};
    _pins[4] = {"output6", "output", nts::Tristate::Undefined};
    _pins[13] = {"output7", "output", nts::Tristate::Undefined};
    _pins[12] = {"output8", "output", nts::Tristate::Undefined};
    _pins[14] = {"output9", "output", nts::Tristate::Undefined};
    _pins[15] = {"output10", "output", nts::Tristate::Undefined};
    _pins[1] = {"output11", "output", nts::Tristate::Undefined};

    _pins[8] = {"Empty", "input", nts::Tristate::Undefined};
    _pins[16] = {"Empty", "input", nts::Tristate::Undefined};
}

nts::Component4040::~Component4040() {}

size_t nts::Component4040::getMaxPin() const {
    return 16;
}

std::string nts::Component4040::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4040::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
    if (pin == 10)
        _linkedClockComponent = &other;
}

nts::Tristate nts::Component4040::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4040::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;

}

void nts::Component4040::simulate(std::size_t tick) {
    (void)tick;

    std::vector<size_t> outputs = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1};
    std::vector<size_t> binary = {1, 2, 4, 8,  16, 32, 64, 128, 256, 512, 1024, 2048};
    bool full = false;

    if (tick == 0)
        return;
    if (getPinState(11) == nts::Tristate::True)
        counter = 0;
    nts::Tristate clockValue = _linkedClockComponent->getPinState(1);
    _pins[10]._value = clockValue;
    _previousClock = _linkedClockComponent->getPrevValue();
    if (_previousClock == nts::Tristate::True && getPinState(10) == nts::Tristate::False)
        counter++;

    for (size_t i = 0; i < 12; i++) {
        if (_pins[outputs[i]]._value != nts::Tristate::True)
            full = false;
    }
    if (full == true) {
        for (size_t i = 0; i < 12; i++)
            _pins[outputs[i]]._value = nts::Tristate::False;
        counter = 0;
        return;
    }
    if (counter == 0 && full != true) {
        for (size_t i = 0; i < 12; i++)
            setPinState(outputs[i], nts::Tristate::Undefined);
        return;
    }
    for (size_t i = 0; i < 12; i++) {
        setPinState(outputs[i], nts::Tristate::False);
    }
    for (size_t i = 0; i < 12; i++) {
        if (counter & binary[i])
            setPinState(outputs[i], nts::Tristate::True);
    }
}

nts::Tristate nts::Component4040::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
