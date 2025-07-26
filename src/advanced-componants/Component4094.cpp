/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4094
*/

#include "Component4094.hpp"

nts::Component4094::Component4094(std::string const &value,
    ComponentFactory &factory) : _factory(factory), _clock("clock") {

    _name = value;
    MAX_PIN = 15;

    //clock
    _pins[3] = {"clock", "input", nts::Tristate::Undefined};
    // input
    _pins[2] = {"data", "input", nts::Tristate::Undefined};
    //output
    _pins[4] = {"out0", "output", nts::Tristate::Undefined};
    _pins[5] = {"out1", "output", nts::Tristate::Undefined};
    _pins[6] = {"out2", "output", nts::Tristate::Undefined};
    _pins[7] = {"out3", "output", nts::Tristate::Undefined};
    _pins[14] = {"out4", "output", nts::Tristate::Undefined};
    _pins[13] = {"out5", "output", nts::Tristate::Undefined};
    _pins[12] = {"out6", "output", nts::Tristate::Undefined};
    _pins[11] = {"out7", "output", nts::Tristate::Undefined};

    _pins[9] = {"out_qs", "output", nts::Tristate::Undefined};
    _pins[10] = {"out_qe", "output", nts::Tristate::Undefined};
    //true
    _pins[1] = {"strob", "input", nts::Tristate::Undefined};
    _pins[15] = {"enable", "input", nts::Tristate::Undefined};

    _pins[8] = {"Ignored", "output", nts::Tristate::Undefined};
}

nts::Component4094::~Component4094() {}

size_t nts::Component4094::getMaxPin() const {
    return MAX_PIN;
}

void nts::Component4094::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4094::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4094::setPinState(std::size_t pin,
    nts::Tristate state) {
    _pins[pin]._value = state;
    if (pin == 3)
        _clock.setPinState(1, state);
}

void nts::Component4094::simulate(std::size_t tick) {
    if (_pins[3]._value == nts::Tristate::True) {
        nts::Tristate data = _pins[2]._value;

        std::vector<int> outputPins = {4, 5, 6, 7, 14, 13, 12, 11};

        std::vector<nts::Tristate> tempValues(8);
        for (std::size_t i = 0; i < outputPins.size(); ++i)
            tempValues[i] = _pins[outputPins[i]]._value;
        for (std::size_t i = outputPins.size() - 1; i > 0; --i)
            tempValues[i] = tempValues[i - 1];
        tempValues[0] = data;
        for (std::size_t i = 0; i < outputPins.size(); ++i)
            _pins[outputPins[i]]._value = tempValues[i];
        _pins[9]._value = _pins[4]._value;
        _pins[10]._value = tempValues[7];
    }
    _clock.simulate(0);
    _lastClockState = _clock.getCurrent();
    _pins[3]._value = _clock.getNextValue();
    if (_lastClockState == nts::Tristate::False && _pins[3]._value == nts::Tristate::True)
        _pins[9]._value = _pins[12]._value;
    else if (_lastClockState == nts::Tristate::True && _pins[3]._value == nts::Tristate::False)
        _pins[10]._value = _pins[12]._value;
}

std::string nts::Component4094::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Component4094::compute(std::size_t pin) {
    if (_pins.find(pin) != _pins.end()) {
        return _pins[pin]._value;
    }
    return nts::Tristate::Undefined;
}
