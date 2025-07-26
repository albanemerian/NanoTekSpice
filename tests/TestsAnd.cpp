/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsAnd
*/

#include "../src/componant/And.hpp"
#include "../src/logic/logic.hpp"
#include "../src/componant/Pin.hpp"
#include <criterion/criterion.h>

Test(AndComponent, Initialization) {
    nts::And andComponent("and1");
    cr_assert_eq(andComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(AndComponent, ComputeUndefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::Undefined);
    andComponent.setPinState(2, nts::Tristate::Undefined);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
}

Test(AndComponent, ComputeTrue) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::True);
}

Test(AndComponent, ComputeFalse) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::False);
    andComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
}

Test(AndComponent, SetLink) {
    nts::And andComponent1("and1");
    nts::And andComponent2("and2");
    andComponent1.setPinState(1, nts::Tristate::True);
    andComponent1.setPinState(2, nts::Tristate::True);
    andComponent1.setLink(3, andComponent2, 1);
    cr_assert_eq(andComponent2.getPinState(1), nts::Tristate::True);
}

Test(AndComponent, ComputeMixed) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
}

Test(AndComponent, ComputeWithUndefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::Undefined);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
}

Test(AndComponent, SetPinStateOutput) {
    nts::And andComponent("and1");
    andComponent.setPinState(3, nts::Tristate::True);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::True);
}

Test(AndComponent, SetLinkUndefined) {
    nts::And andComponent1("and1");
    nts::And andComponent2("and2");
    andComponent1.setPinState(1, nts::Tristate::Undefined);
    andComponent1.setLink(1, andComponent2, 1);
    cr_assert_eq(andComponent2.getPinState(1), nts::Tristate::Undefined);
}

Test(AndComponent, Simulate) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    andComponent.simulate(1);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::True);
}

Test(AndComponent, SimulateUndefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::Undefined);
    andComponent.setPinState(2, nts::Tristate::True);
    andComponent.simulate(1);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(AndComponent, ComputePinNotOutput) {
    nts::And andComponent("and1");
    cr_assert_eq(andComponent.compute(1), nts::Tristate::Undefined);
}

Test(AndComponent, SetPinStateInput1Undefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::Undefined);
    andComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(AndComponent, SetPinStateInput2Undefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(AndComponent, SetPinStateBothInputsUndefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::Undefined);
    andComponent.setPinState(2, nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(AndComponent, SetPinStateBothInputsDefined) {
    nts::And andComponent("and1");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::True);
}

Test(AndComponent, SetLinkInputUndefined) {
    nts::And andComponent1("and1");
    nts::And andComponent2("and2");
    andComponent1.setPinState(1, nts::Tristate::Undefined);
    andComponent1.setLink(1, andComponent2, 1);
    cr_assert_eq(andComponent2.getPinState(1), nts::Tristate::Undefined);
}

Test(AndComponent, SetLinkInputDefined) {
    nts::And andComponent1("and1");
    nts::And andComponent2("and2");
    andComponent1.setPinState(1, nts::Tristate::True);
    andComponent1.getMaxPin();
    andComponent1.setLink(1, andComponent2, 1);
    cr_assert_eq(andComponent2.getPinState(1), nts::Tristate::True);
}

Test(AndComponent, GetPinType) {
    nts::And andComponent1("and1");
    cr_assert_eq(andComponent1.getPinType(1), "input");
    cr_assert_eq(andComponent1.getPinType(2), "input");
    cr_assert_eq(andComponent1.getPinType(3), "output");
}

Test(AndComponent, GetPrevValue) {
    nts::And andComponent1("and1");
    cr_assert_eq(andComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(AndComponent, GetNextValue) {
    nts::And andComponent1("and1");
    cr_assert_eq(andComponent1.getNextValue(), nts::Tristate::Undefined);
}
