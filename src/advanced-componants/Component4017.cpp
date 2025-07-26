/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4017
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "../logic/logic.hpp"
#include "Component4017.hpp"


nts::Component4017::Component4017(std::string const &value,
    ComponentFactory &factory) : _factory(factory),
    _notCP1("notCP1"), _orComp("orComp"), _flipFlop1("flipFlop1"),
    _flipFlop2("flipFlop2"), _flipFlop3("flipFlop3"), _flipFlop4("flipFlop4"),
    _flipFlop5("flipFlop5"), _andClock("andClock"), _andOr("andOr"),
    _norOutput0("norOutput0"), _norOutput1("norOutput1"), _norOutput2("norOutput2"),
    _norOutput3("norOutput3"), _norOutput4("norOutput4"), _norOutput5("norOutput5"),
    _norOutput6("norOutput6"), _norOutput7("norOutput7"), _norOutput8("norOutput8"),
    _norOutput9("norOutput9") {
    _name = value;
    MAX_PIN = 16;
    counter = 0;
    _previousClock1 = nts::Tristate::Undefined;
    _previousClock2 = nts::Tristate::Undefined;
    _pins[1] = {"output1", "output", nts::Tristate::Undefined};
    _pins[2] = {"output2", "output", nts::Tristate::Undefined};
    _pins[3] = {"output3", "output", nts::Tristate::Undefined};
    _pins[4] = {"output4", "output", nts::Tristate::Undefined};
    _pins[5] = {"output5", "output", nts::Tristate::Undefined};
    _pins[6] = {"output6", "output", nts::Tristate::Undefined};
    _pins[7] = {"output7", "output", nts::Tristate::Undefined};
    _pins[9] = {"output8", "output", nts::Tristate::Undefined};
    _pins[10] = {"output9", "output", nts::Tristate::Undefined};
    _pins[11] = {"output10", "output", nts::Tristate::Undefined};
    _pins[12] = {"output S", "output", nts::Tristate::Undefined};
    _pins[13] = {"clock1", "clock", nts::Tristate::Undefined};
    _pins[14] = {"clock2", "clock", nts::Tristate::Undefined};
    _pins[15] = {"reset", "input", nts::Tristate::Undefined};
    _pins[8] = {"empty", "input", nts::Tristate::Undefined};
    _pins[16] = {"empty", "input", nts::Tristate::Undefined};
}


nts::Component4017::~Component4017() {}

size_t nts::Component4017::getMaxPin() const {
    return 16;
}

std::string nts::Component4017::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4017::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4017::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4017::setPinState(std::size_t pin, nts::Tristate state) {
    if (pin == 14) {
        _previousClock1 = _pins[14]._value;
    }
    if (pin == 13)
        _previousClock2 = _pins[13]._value;
    _pins[pin]._value = state;
}

void nts::Component4017::simulate(std::size_t tick) {
    if (tick == 0)
        return;

    _prevFlip1 = _andClock.getPinState(3);  // Q1
    _prevFlip2 = _andClock.getPinState(3);  // Q2
    _prevFlip3 = _andClock.getPinState(3);  // Q3
    _prevFlip4 = _andClock.getPinState(3);  // Q4
    _prevFlip5 = _andClock.getPinState(3);  // Q5

    _flipFlop1.setPrev(_prevFlip1);
    _flipFlop2.setPrev(_prevFlip2);
    _flipFlop3.setPrev(_prevFlip3);
    _flipFlop4.setPrev(_prevFlip4);
    _flipFlop5.setPrev(_prevFlip5);

    // **Clock Handling**
    _notCP1.setPinState(1, _pins[13]._value);  // Invert CP1
    _andClock.setPinState(1, _pins[14]._value);  // CP0
    _andClock.setPinState(2, _notCP1.compute(2));  // AND with inverted CP1

    // **Flip-Flop Clocking**
    _flipFlop1.setPinState(3, _andClock.compute(3));
    _flipFlop2.setPinState(3, _andClock.compute(3));
    _flipFlop3.setPinState(3, _andClock.compute(3));
    _flipFlop4.setPinState(3, _andClock.compute(3));
    _flipFlop5.setPinState(3, _andClock.compute(3));

    // **Reset Handling**
    _flipFlop1.setPinState(4, getPinState(15));  // Master Reset
    _flipFlop2.setPinState(4, getPinState(15));
    _flipFlop3.setPinState(4, getPinState(15));
    _flipFlop4.setPinState(4, getPinState(15));
    _flipFlop5.setPinState(4, getPinState(15));

    _flipFlop1.simulate(tick);
    _flipFlop2.simulate(tick);
    _flipFlop3.simulate(tick);
    _flipFlop4.simulate(tick);
    _flipFlop5.simulate(tick);

    // **Johnson Counter Feedback**
    _flipFlop1.setPinState(5, _flipFlop5.getPinState(2));  // D1 = Q̅5
    _flipFlop2.setPinState(5, _flipFlop1.getPinState(1));  // D2 = Q1
    _flipFlop3.setPinState(5, _flipFlop2.getPinState(1));  // D3 = Q2
    _flipFlop4.setPinState(5, _flipFlop3.getPinState(1));  // D4 = Q3
    _flipFlop5.setPinState(5, _flipFlop4.getPinState(1));  // D5 = Q4

    // **OR and AND Logic (Single OR Gate)**
    _orComp.setPinState(1, _flipFlop1.getPinState(1));  // Q5
    _orComp.setPinState(2, _flipFlop3.getPinState(1));  // Q4

    _andOr.setPinState(1, _orComp.compute(3));
    _andOr.setPinState(2, _flipFlop2.getPinState(1));  // Q3

    // **NOR Outputs**
    _norOutput0.setPinState(1, _flipFlop1.getPinState(1));  // Q1
    _norOutput0.setPinState(2, _flipFlop5.getPinState(1));  // Q5

    _norOutput1.setPinState(1, _flipFlop2.getPinState(1));  // Q2
    _norOutput1.setPinState(2, _flipFlop1.getPinState(2));  // Q2

    _norOutput2.setPinState(1, _flipFlop3.getPinState(1));  // Q3
    _norOutput2.setPinState(2, _flipFlop2.getPinState(2));  // Q3

    _norOutput3.setPinState(1, _flipFlop4.getPinState(1));  // Q4
    _norOutput3.setPinState(2, _flipFlop3.getPinState(2));  // Q4

    _norOutput4.setPinState(1, _flipFlop5.getPinState(1));  // Q5
    _norOutput4.setPinState(2, _flipFlop4.getPinState(2));  // Q5

    _norOutput5.setPinState(1, _flipFlop5.getPinState(2));
    _norOutput5.setPinState(2, _flipFlop1.getPinState(2));

    _norOutput6.setPinState(1, _flipFlop1.getPinState(1));
    _norOutput6.setPinState(2, _flipFlop2.getPinState(2));

    _norOutput7.setPinState(1, _flipFlop2.getPinState(1));
    _norOutput7.setPinState(2, _flipFlop3.getPinState(2));

    _norOutput8.setPinState(1, _flipFlop3.getPinState(1));
    _norOutput8.setPinState(2, _flipFlop4.getPinState(2));

    _norOutput9.setPinState(1, _flipFlop4.getPinState(1));
    _norOutput9.setPinState(2, _flipFlop5.getPinState(2));

    // Simulate all components
    _notCP1.simulate(tick);
    _andClock.simulate(tick);

    _orComp.simulate(tick);
    _andOr.simulate(tick);
    _norOutput0.simulate(tick);
    _norOutput1.simulate(tick);
    _norOutput2.simulate(tick);
    _norOutput3.simulate(tick);
    _norOutput4.simulate(tick);
    _norOutput5.simulate(tick);
    _norOutput6.simulate(tick);
    _norOutput7.simulate(tick);
    _norOutput8.simulate(tick);
    _norOutput9.simulate(tick);

    _pins[3]._value = _norOutput0.getPinState(3);
    _pins[2]._value = _norOutput1.getPinState(3);
    _pins[4]._value = _norOutput2.getPinState(3);
    _pins[7]._value = _norOutput3.getPinState(3);
    _pins[10]._value = _norOutput4.getPinState(3);
    _pins[1]._value = _norOutput5.getPinState(3);
    _pins[5]._value = _norOutput6.getPinState(3);
    _pins[6]._value = _norOutput7.getPinState(3);
    _pins[9]._value = _norOutput8.getPinState(3);
    _pins[11]._value = _norOutput9.getPinState(3);
    _pins[12]._value = _flipFlop5.getPinState(2);
}



nts::Tristate nts::Component4017::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}
