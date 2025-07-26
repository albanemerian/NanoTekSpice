/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestXor
*/

#include "../src/componant/Xor.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(XorComponent, Initialization) {
    nts::Xor xorGate("xor1");

    cr_assert_eq(xorGate.getMaxPin(), 3);
    cr_assert_eq(xorGate.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(xorGate.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(xorGate.getPinState(3), nts::Tristate::Undefined);
}

Test(XorComponent, ComputeUndefined) {
    nts::Xor xorGate("xor1");

    cr_assert_eq(xorGate.compute(1), nts::Tristate::Undefined);
    cr_assert_eq(xorGate.compute(2), nts::Tristate::Undefined);
    cr_assert_eq(xorGate.compute(3), nts::Tristate::Undefined);
}

Test(XorComponent, ComputeLogic) {
    nts::Xor xorGate("xor1");

    xorGate.setPinState(1, nts::Tristate::True);
    xorGate.setPinState(2, nts::Tristate::False);
    cr_assert_eq(xorGate.compute(3), nts::Tristate::True);

    xorGate.setPinState(1, nts::Tristate::True);
    xorGate.setPinState(2, nts::Tristate::True);
    cr_assert_eq(xorGate.compute(3), nts::Tristate::False);

    xorGate.setPinState(1, nts::Tristate::False);
    xorGate.setPinState(2, nts::Tristate::False);
    cr_assert_eq(xorGate.compute(3), nts::Tristate::False);

    xorGate.setPinState(1, nts::Tristate::False);
    xorGate.setPinState(2, nts::Tristate::True);
    cr_assert_eq(xorGate.compute(3), nts::Tristate::True);
}

Test(XorComponent, SetLink) {
    nts::Xor xorGate1("xor1");
    nts::Xor xorGate2("xor2");

    xorGate1.setPinState(1, nts::Tristate::True);
    xorGate1.setPinState(2, nts::Tristate::False);
    xorGate1.setLink(3, xorGate2, 1);

    cr_assert_eq(xorGate2.getPinState(1), nts::Tristate::True);
}

Test(XorComponent, Simulate) {
    nts::Xor xorGate("xor1");

    xorGate.setPinState(1, nts::Tristate::True);
    xorGate.setPinState(2, nts::Tristate::False);
    xorGate.simulate(1);
    cr_assert_eq(xorGate.getPinState(3), nts::Tristate::True);

    xorGate.setPinState(1, nts::Tristate::True);
    xorGate.setPinState(2, nts::Tristate::True);
    xorGate.simulate(1);
    cr_assert_eq(xorGate.getPinState(3), nts::Tristate::False);
}

Test(XorComponent, GetPinType) {
    nts::Xor XorComponent1("Xor1");
    cr_assert_eq(XorComponent1.getPinType(1), "input");
    cr_assert_eq(XorComponent1.getPinType(2), "input");
    cr_assert_eq(XorComponent1.getPinType(3), "output");
}

Test(XorComponent, GetPrevValue) {
    nts::Xor XorComponent1("Xor1");
    cr_assert_eq(XorComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(XorComponent, GetNextValue) {
    nts::Xor XorComponent1("Xor1");
    cr_assert_eq(XorComponent1.getNextValue(), nts::Tristate::Undefined);
}
