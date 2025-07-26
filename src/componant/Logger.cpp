/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Logger
*/

#include "Logger.hpp"

nts::Logger::Logger(const std::string &value) {
    MAX_PIN = 10;
    std::ofstream _BinFile("log.bin");
    _valu = "l";
    _pins[1]._name = "input1";
    _pins[1]._type = "input";
    _pins[1]._value = nts::Tristate::Undefined;

    _pins[2]._name = "input2";
    _pins[2]._type = "input";
    _pins[2]._value = nts::Tristate::Undefined;

    _pins[3]._name = "input3";
    _pins[3]._type = "input";
    _pins[3]._value = nts::Tristate::Undefined;

    _pins[4]._name = "input4";
    _pins[4]._type = "input";
    _pins[4]._value = nts::Tristate::Undefined;

    _pins[5]._name = "input5";
    _pins[5]._type = "input";
    _pins[5]._value = nts::Tristate::Undefined;

    _pins[6]._name = "input6";
    _pins[6]._type = "input";
    _pins[6]._value = nts::Tristate::Undefined;

    _pins[7]._name = "input7";
    _pins[7]._type = "input";
    _pins[7]._value = nts::Tristate::Undefined;

    _pins[8]._name = "input8";
    _pins[8]._type = "input";
    _pins[8]._value = nts::Tristate::Undefined;

    _pins[9]._name = "clock";
    _pins[9]._type = "clock";
    _pins[9]._value = nts::Tristate::Undefined;

    _pins[10]._name = "inhibit";
    _pins[10]._type = "input";
    _pins[10]._value = nts::Tristate::Undefined;
    _name = value;
}

nts::Logger::~Logger() {}

size_t  nts::Logger::getMaxPin() const {
    return MAX_PIN;
}

nts::Tristate nts::Logger::getPrevValue() const {
    return nts::Tristate::Undefined;
}

void nts::Logger::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

nts::Tristate nts::Logger::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

std::string nts::Logger::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

nts::Tristate nts::Logger::getNextValue() const {
    return nts::Tristate::Undefined;
}

void nts::Logger::update() {

    if (_pins[9]._value == nts::Tristate::Undefined)
        return;
    if (_pins[10]._value != nts::Tristate::False)
        return;
    if (_pins[9]._value == nts::Tristate::True && _prevValue == nts::Tristate::False
        && _pins[10]._value == nts::Tristate::False && _asWritten == false) {
        char character = 0;
        for (int i = 1; i <= 8; ++i) {
            if (_pins[i]._value == nts::Tristate::True) {
                character |= (1 << (i - 1));
            }
            if (_pins[i]._value == nts::Tristate::Undefined) {
                _asWritten = false;
                return;
            }
        }
        _valu.clear();
        _valu += character;
        std::ofstream _BinFile("log.bin", std::ios::app | std::ios::binary);
        if (_BinFile.is_open()) {
            _BinFile.write(_valu.c_str(), 1);
            _BinFile.close();
        } else {
            std::cerr << "Error: Unable to open log.bin" << std::endl;
        }
        _asWritten = true;
    }
    if (_pins[9]._value == nts::Tristate::False)
        _asWritten = false;
}

nts::Tristate nts::Logger::compute(std::size_t pin) {
    (void)pin;
    update();
    return nts::Tristate::Undefined;
}

void nts::Logger::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
    if (pin == 9)
        _linkedClockComponent = &other;
}


void nts::Logger::simulate(std::size_t tick) {
    (void)tick;
    if (tick != 0) {
        nts::Tristate clockValue = _linkedClockComponent->getPinState(1);
        _pins[9]._value = clockValue;
        _prevValue = _linkedClockComponent->getPrevValue();
    }
    compute(3);
}
