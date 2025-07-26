/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4801
*/

#include <iostream>
#include <bitset>
#include <cstring>
#include "Component4801.hpp"
#include "../logic/logic.hpp"

nts::Component4801::Component4801(std::string const &value,
    ComponentFactory &factory) : _factory(factory) {
    _name = value;
    MAX_PIN = 24;

    _pins[18] = {"activated", "input", nts::Tristate::Undefined};
    _pins[20] = {"read", "input", nts::Tristate::Undefined};
    _pins[21] = {"write", "input", nts::Tristate::Undefined};

    //adresses
    _pins[8] = {"address0", "input", nts::Tristate::Undefined};
    _pins[7] = {"address1", "input", nts::Tristate::Undefined};
    _pins[6] = {"address2", "input", nts::Tristate::Undefined};
    _pins[5] = {"address3", "input", nts::Tristate::Undefined};
    _pins[4] = {"address4", "input", nts::Tristate::Undefined};
    _pins[3] = {"address5", "input", nts::Tristate::Undefined};
    _pins[2] = {"address6", "input", nts::Tristate::Undefined};
    _pins[1] = {"address7", "input", nts::Tristate::Undefined};
    _pins[22] = {"address8", "input", nts::Tristate::Undefined};
    _pins[23] = {"address9", "input", nts::Tristate::Undefined};

    //message in
    _pins[9] = {"msg0", "input", nts::Tristate::Undefined};
    _pins[10] = {"msg1", "input", nts::Tristate::Undefined};
    _pins[11] = {"msg2", "input", nts::Tristate::Undefined};
    _pins[12] = {"msg3", "input", nts::Tristate::Undefined};
    _pins[13] = {"msg4", "input", nts::Tristate::Undefined};
    _pins[14] = {"msg5", "input", nts::Tristate::Undefined};
    _pins[15] = {"msg6", "input", nts::Tristate::Undefined};
    _pins[16] = {"msg7", "input", nts::Tristate::Undefined};
    _pins[17] = {"msg8", "input", nts::Tristate::Undefined};
    _ram = new char[1024 * 8];
    memset(_ram, 0, 1024 * 8);
}

nts::Component4801::~Component4801() {}

size_t nts::Component4801::getMaxPin() const {
    return MAX_PIN;
}

std::string nts::Component4801::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4801::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4801::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4801::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4801::simulate(std::size_t tick) {
    (void)tick;
    if (_pins[18]._value == nts::Tristate::True) {
        compute(18);
    }
}

nts::Tristate nts::Component4801::compute(std::size_t pin) {
    std::bitset<10> address;
    std::bitset<9> data;

    for (int i = 0; i < 10; i++) {
        if (_pins[8 - i]._value == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        address[i] = (_pins[8 - i]._value == nts::Tristate::True);
    }

    size_t addrIndex = address.to_ulong();
    if (_pins[21]._value == nts::Tristate::False) {
        char byte = 0;
        for (int i = 0; i < 9; i++) {
            if (_pins[9 + i]._value == nts::Tristate::Undefined)
                return nts::Tristate::Undefined;
            if (_pins[9 + i]._value == nts::Tristate::True)
                byte |= (1 << i);
        }
        _ram[addrIndex] = byte;
    }
    else if (_pins[20]._value == nts::Tristate::False) {
        char byte = _ram[addrIndex];
        for (int i = 0; i < 9; i++) {
            _pins[9 + i]._value = (byte & (1 << i)) ? nts::Tristate::True : nts::Tristate::False;
        }
    } else {
        for (int i = 0; i < 9; i++)
            _pins[9 + i]._value = nts::Tristate::Undefined;
    }

    return getPinState(pin);
}
