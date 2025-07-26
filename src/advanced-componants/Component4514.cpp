/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4514
*/

#include <tuple>
#include <vector>
#include <iostream>
#include "../logic/logic.hpp"
#include "Component4514.hpp"

nts::Component4514::Component4514(std::string const &value,
    ComponentFactory &factory) : _factory(factory),
    _notIn0("notIn0"), _and0_0("and0_0"), _and0_1("and0_1"),
    _notIn1("notIn1"), _and1_0("and1_0"), _and1_1("and1_1"),
    _notIn2("notIn2"), _and2_0("and2_0"), _and2_1("and2_1"),
    _notIn3("notIn3"), _and3_0("and3_0"), _and3_1("and3_1"),

    _notStrobe("notStrobe"), _notInhibit("notInhibit"),

    _flipflop1("flipflop1"), _flipflop2("flipflop2"),
    _flipflop3("flipflop3"), _flipflop4("flipflop4"),

    _andFlip1("andFlip1"), _andFlip2("andFlip2"),
    _andFlip3("andFlip3"), _andFlip4("andFlip4"),
    _andFlip5("andFlip5"), _andFlip6("andFlip6"),
    _andFlip7("andFlip7"), _andFlip8("andFlip8"),

    _andOutput0("andOutput0"), _andOutput1("andOutput1"),
    _andOutput2("andOutput2"), _andOutput3("andOutput3"),
    _andOutput4("andOutput4"), _andOutput5("andOutput5"),
    _andOutput6("andOutput6"), _andOutput7("andOutput7"),
    _andOutput8("andOutput8"), _andOutput9("andOutput9"),
    _andOutput10("andOutput10"), _andOutput11("andOutput11"),
    _andOutput12("andOutput12"), _andOutput13("andOutput13"),
    _andOutput14("andOutput14"), _andOutput15("andOutput15"),

    _notOutput0("notOutput0"), _notOutput1("notOutput1"),
    _notOutput2("notOutput2"), _notOutput3("notOutput3"),
    _notOutput4("notOutput4"), _notOutput5("notOutput5"),
    _notOutput6("notOutput6"), _notOutput7("notOutput7"),
    _notOutput8("notOutput8"), _notOutput9("notOutput9"),
    _notOutput10("notOutput10"), _notOutput11("notOutput11"),
    _notOutput12("notOutput12"), _notOutput13("notOutput13"),
    _notOutput14("notOutput14"), _notOutput15("notOutput15") {
    _name = value;
    MAX_PIN = 24;
    //input
    _pins[1] = {"input1", "input", nts::Tristate::Undefined};
    _pins[2] = {"input2", "input", nts::Tristate::Undefined};
    _pins[3] = {"input3", "input", nts::Tristate::Undefined};
    _pins[21] = {"input4", "input", nts::Tristate::Undefined};
    _pins[22] = {"input5", "input", nts::Tristate::Undefined};
    _pins[23] = {"input6", "input", nts::Tristate::Undefined};

    //output
    _pins[4] = {"output1", "output", nts::Tristate::Undefined};
    _pins[5] = {"output2", "output", nts::Tristate::Undefined};
    _pins[6] = {"output3", "output", nts::Tristate::Undefined};
    _pins[7] = {"output4", "output", nts::Tristate::Undefined};
    _pins[8] = {"output5", "output", nts::Tristate::Undefined};
    _pins[9] = {"output6", "output", nts::Tristate::Undefined};
    _pins[10] = {"output7", "output", nts::Tristate::Undefined};
    _pins[11] = {"output8", "output", nts::Tristate::Undefined};

    _pins[13] = {"output10", "output", nts::Tristate::Undefined};
    _pins[14] = {"output11", "output", nts::Tristate::Undefined};
    _pins[15] = {"output12", "output", nts::Tristate::Undefined};
    _pins[16] = {"output13", "output", nts::Tristate::Undefined};
    _pins[17] = {"output14", "output", nts::Tristate::Undefined};
    _pins[18] = {"output15", "output", nts::Tristate::Undefined};
    _pins[19] = {"output16", "output", nts::Tristate::Undefined};
    _pins[20] = {"output17", "output", nts::Tristate::Undefined};
}

nts::Component4514::~Component4514() {}

size_t nts::Component4514::getMaxPin() const {
    return 24;
}

void nts::Component4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    other.setPinState(otherPin, getPinState(pin));
}

nts::Tristate nts::Component4514::getPinState(std::size_t pin) {
    return _pins[pin]._value;
}

void nts::Component4514::setPinState(std::size_t pin, nts::Tristate state) {
    _pins[pin]._value = state;
}

std::string nts::Component4514::getPinType(std::size_t pin) {
    return _pins[pin]._type;
}

void nts::Component4514::simulate(std::size_t tick) {

    _notIn0.setPinState(1, getPinState(2));
    _notIn1.setPinState(1, getPinState(3));
    _notIn2.setPinState(1, getPinState(21));
    _notIn3.setPinState(1, getPinState(22));
    _notStrobe.setPinState(1, getPinState(1));
    _notInhibit.setPinState(1, getPinState(23));


    _and0_0.setPinState(1, _notIn0.compute(2));
    _and0_0.setPinState(2, _notStrobe.compute(2));

    _and0_1.setPinState(1, _and0_0.compute(3));
    _and0_1.setPinState(2, _notStrobe.compute(2));

    _and1_0.setPinState(1, _notIn1.compute(2));
    _and1_0.setPinState(2, _notStrobe.compute(2));

    _and1_1.setPinState(1, _and1_0.compute(3));
    _and1_1.setPinState(2, _notStrobe.compute(2));

    _and2_0.setPinState(1, _notIn2.compute(2));
    _and2_0.setPinState(2, _notStrobe.compute(2));

    _and2_1.setPinState(1, _notStrobe.compute(2));
    _and2_1.setPinState(2, _and2_0.compute(3));

    _and3_0.setPinState(1, _notIn3.compute(2));
    _and3_0.setPinState(2, _notStrobe.compute(2));

    _and3_1.setPinState(1, _notStrobe.compute(2));
    _and3_1.setPinState(2, _and3_0.compute(3));

    _flipflop1.setPinState(6, _and0_0.compute(3));
    _flipflop1.setPinState(4, _and0_1.compute(3));

    _flipflop2.setPinState(6, _and1_0.compute(3));
    _flipflop2.setPinState(4, _and1_1.compute(3));

    _flipflop3.setPinState(6, _and2_0.compute(3));
    _flipflop3.setPinState(4, _and2_1.compute(3));

    _flipflop4.setPinState(6, _and3_0.compute(3));
    _flipflop4.setPinState(4, _and3_1.compute(3));


    _flipflop1.simulate(tick);
    _flipflop2.simulate(tick);
    _flipflop3.simulate(tick);
    _flipflop4.simulate(tick);

    _andFlip1.setPinState(1, _flipflop1.getPinState(1));
    _andFlip1.setPinState(2, _flipflop2.getPinState(1));

    _andFlip2.setPinState(1, _flipflop1.getPinState(2));
    _andFlip2.setPinState(2, _flipflop2.getPinState(1));

    _andFlip3.setPinState(1, _flipflop1.getPinState(1));
    _andFlip3.setPinState(2, _flipflop2.getPinState(2));

    _andFlip4.setPinState(1, _flipflop1.getPinState(2));
    _andFlip4.setPinState(2, _flipflop2.getPinState(2));


    _andFlip5.setPinState(1, _flipflop3.getPinState(1));
    _andFlip5.setPinState(2, _flipflop4.getPinState(1));

    _andFlip6.setPinState(1, _flipflop3.getPinState(2));
    _andFlip6.setPinState(2, _flipflop4.getPinState(1));

    _andFlip7.setPinState(1, _flipflop3.getPinState(1));
    _andFlip7.setPinState(2, _flipflop4.getPinState(2));

    _andFlip8.setPinState(1, _flipflop3.getPinState(2));
    _andFlip8.setPinState(2, _flipflop4.getPinState(2));


    _andOutput0.setPinState(1, _andFlip1.compute(3));
    _andOutput0.setPinState(2, _andFlip5.compute(3));
    _andOutput0.setPinState(3, _notInhibit.compute(2));

    _andOutput1.setPinState(1, _andFlip2.compute(3));
    _andOutput1.setPinState(2, _andFlip5.compute(3));
    _andOutput1.setPinState(3, _notInhibit.compute(2));

    _andOutput2.setPinState(1, _andFlip3.compute(3));
    _andOutput2.setPinState(2, _andFlip5.compute(3));
    _andOutput2.setPinState(3, _notInhibit.compute(2));

    _andOutput3.setPinState(1, _andFlip4.compute(3));
    _andOutput3.setPinState(2, _andFlip5.compute(3));
    _andOutput3.setPinState(3, _notInhibit.compute(2));

    _andOutput4.setPinState(1, _andFlip1.compute(3));
    _andOutput4.setPinState(2, _andFlip6.compute(3));
    _andOutput4.setPinState(3, _notInhibit.compute(2));

    _andOutput5.setPinState(1, _andFlip2.compute(3));
    _andOutput5.setPinState(2, _andFlip6.compute(3));
    _andOutput5.setPinState(3, _notInhibit.compute(2));

    _andOutput6.setPinState(1, _andFlip3.compute(3));
    _andOutput6.setPinState(2, _andFlip6.compute(3));
    _andOutput6.setPinState(3, _notInhibit.compute(2));


    _andOutput7.setPinState(1, _andFlip4.compute(3));
    _andOutput7.setPinState(2, _andFlip6.compute(3));
    _andOutput7.setPinState(3, _notInhibit.compute(2));


    _andOutput8.setPinState(1, _andFlip1.compute(3));
    _andOutput8.setPinState(2, _andFlip7.compute(3));
    _andOutput8.setPinState(3, _notInhibit.compute(2));

    _andOutput9.setPinState(1, _andFlip2.compute(3));
    _andOutput9.setPinState(2, _andFlip7.compute(3));
    _andOutput9.setPinState(3, _notInhibit.compute(2));

    _andOutput10.setPinState(1, _andFlip3.compute(3));
    _andOutput10.setPinState(2, _andFlip7.compute(3));
    _andOutput10.setPinState(3, _notInhibit.compute(2));

    _andOutput11.setPinState(1, _andFlip4.compute(3));
    _andOutput11.setPinState(2, _andFlip7.compute(3));
    _andOutput11.setPinState(3, _notInhibit.compute(2));


    _andOutput12.setPinState(1, _andFlip1.compute(3));
    _andOutput12.setPinState(2, _andFlip8.compute(3));
    _andOutput12.setPinState(3, _notInhibit.compute(2));

    _andOutput13.setPinState(1, _andFlip2.compute(3));
    _andOutput13.setPinState(2, _andFlip8.compute(3));
    _andOutput13.setPinState(3, _notInhibit.compute(2));

    _andOutput14.setPinState(1, _andFlip3.compute(3));
    _andOutput14.setPinState(2, _andFlip8.compute(3));
    _andOutput14.setPinState(3, _notInhibit.compute(2));

    _andOutput15.setPinState(1, _andFlip4.compute(3));
    _andOutput15.setPinState(2, _andFlip8.compute(3));
    _andOutput15.setPinState(3, _notInhibit.compute(2));


    _notOutput0.setPinState(1, _andOutput0.compute(4));
    _pins[11]._value = _notOutput0.compute(2);

    _notOutput1.setPinState(1, _andOutput1.compute(4));
    _pins[9]._value = _notOutput1.compute(2);

    _notOutput2.setPinState(1, _andOutput2.compute(4));
    _pins[10]._value = _notOutput2.compute(2);

    _notOutput3.setPinState(1, _andOutput3.compute(4));
    _pins[8]._value = _notOutput3.compute(2);

    _notOutput4.setPinState(1, _andOutput4.compute(4));
    _pins[7]._value = _notOutput4.compute(2);

    _notOutput5.setPinState(1, _andOutput5.compute(4));
    _pins[6]._value = _notOutput5.compute(2);

    _notOutput6.setPinState(1, _andOutput6.compute(4));
    _pins[5]._value = _notOutput6.compute(2);

    _notOutput7.setPinState(1, _andOutput7.compute(4));
    _pins[4]._value = _notOutput7.compute(2);

    _notOutput8.setPinState(1, _andOutput8.compute(4));
    _pins[18]._value = _notOutput8.compute(2);

    _notOutput9.setPinState(1, _andOutput9.compute(4));
    _pins[17]._value = _notOutput9.compute(2);

    _notOutput10.setPinState(1, _andOutput10.compute(4));
    _pins[20]._value = _notOutput10.compute(2);

    _notOutput11.setPinState(1, _andOutput11.compute(4));
    _pins[19]._value = _notOutput11.compute(2);

    _notOutput12.setPinState(1, _andOutput12.compute(4));
    _pins[14]._value = _notOutput12.compute(2);

    _notOutput13.setPinState(1, _andOutput13.compute(4));
    _pins[13]._value = _notOutput13.compute(2);

    _notOutput14.setPinState(1, _andOutput14.compute(4));
    _pins[16]._value = _notOutput14.compute(2);

    _notOutput15.setPinState(1, _andOutput15.compute(4));
    _pins[15]._value = _notOutput15.compute(2);


    _notIn0.simulate(tick);
    _notIn1.simulate(tick);
    _notIn2.simulate(tick);
    _notIn3.simulate(tick);
    _notStrobe.simulate(tick);
    _notInhibit.simulate(tick);

    _and0_0.simulate(tick);
    _and0_1.simulate(tick);
    _and1_0.simulate(tick);
    _and1_1.simulate(tick);
    _and2_0.simulate(tick);
    _and2_1.simulate(tick);
    _and3_0.simulate(tick);
    _and3_1.simulate(tick);



    _andFlip1.simulate(tick);
    _andFlip2.simulate(tick);
    _andFlip3.simulate(tick);
    _andFlip4.simulate(tick);
    _andFlip5.simulate(tick);
    _andFlip6.simulate(tick);
    _andFlip7.simulate(tick);
    _andFlip8.simulate(tick);


    _andOutput0.simulate(tick);
    _andOutput1.simulate(tick);
    _andOutput2.simulate(tick);
    _andOutput3.simulate(tick);
    _andOutput4.simulate(tick);
    _andOutput5.simulate(tick);
    _andOutput6.simulate(tick);
    _andOutput7.simulate(tick);
    _andOutput8.simulate(tick);
    _andOutput9.simulate(tick);
    _andOutput10.simulate(tick);
    _andOutput11.simulate(tick);
    _andOutput12.simulate(tick);
    _andOutput13.simulate(tick);
    _andOutput14.simulate(tick);
    _andOutput15.simulate(tick);


    _notOutput0.simulate(tick);
    _notOutput1.simulate(tick);
    _notOutput2.simulate(tick);
    _notOutput3.simulate(tick);
    _notOutput4.simulate(tick);
    _notOutput5.simulate(tick);
    _notOutput6.simulate(tick);
    _notOutput7.simulate(tick);
    _notOutput8.simulate(tick);
    _notOutput9.simulate(tick);
    _notOutput10.simulate(tick);
    _notOutput11.simulate(tick);
    _notOutput12.simulate(tick);
    _notOutput13.simulate(tick);
    _notOutput14.simulate(tick);
    _notOutput15.simulate(tick);

}


nts::Tristate nts::Component4514::compute(std::size_t pin) {
    simulate(0);
    return getPinState(pin);
}

