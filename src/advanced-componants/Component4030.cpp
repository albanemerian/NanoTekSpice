/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Componant4030
*/


#include "Component4030.hpp"
#include "../logic/logic.hpp"

nts::Component4030::Component4030(std::string const &value,
    ComponentFactory &factory) : _factory(factory), xor1("xor1"), xor2("xor2"),
    xor3("xor3"), xor4("xor4") {
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

nts::Component4030::~Component4030() {}

size_t nts::Component4030::getMaxPin() const {
    return 14;
}

std::string nts::Component4030::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4030::setLink(std::size_t pin, nts::IComponent
    &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4030::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4030::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

void nts::Component4030::simulate(std::size_t tick) {
    xor1.setPinState(1, getPinState(1));
    xor1.setPinState(2, getPinState(2));
    setPinState(3, xor1.computes(1, 2, 3));

    xor2.setPinState(1, getPinState(5));
    xor2.setPinState(2, getPinState(6));
    setPinState(4, xor2.computes(1, 2, 3));

    xor3.setPinState(1, getPinState(8));
    xor3.setPinState(2, getPinState(9));
    setPinState(10, xor3.computes(1, 2, 3));

    xor4.setPinState(1, getPinState(12));
    xor4.setPinState(2, getPinState(13));
    setPinState(11, xor4.computes(1, 2, 3));
    (void)tick;
}

nts::Tristate nts::Component4030::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
