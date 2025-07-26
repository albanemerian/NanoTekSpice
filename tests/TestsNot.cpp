/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsNot
*/

#include "../src/componant/Not.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(NotComponent, Constructor) {
    nts::Not notComponent("TestNot");
    cr_assert_eq(notComponent.getMaxPin(), 3);
    cr_assert_eq(notComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(2), nts::Tristate::Undefined);
}

Test(NotComponent, ComputeUndefined) {
    nts::Not notComponent("TestNot");
    cr_assert_eq(notComponent.compute(1), nts::Tristate::Undefined);
}

Test(NotComponent, ComputeValid) {
    nts::Not notComponent("TestNot");
    notComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(notComponent.compute(2), nts::Tristate::False);
}

Test(NotComponent, SetPinState) {
    nts::Not notComponent("TestNot");
    notComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(notComponent.getPinState(1), nts::Tristate::True);
    cr_assert_eq(notComponent.getPinState(2), nts::Tristate::False);
}

Test(NotComponent, SetLink) {
    nts::Not notComponent("TestNot");
    nts::Not otherComponent("OtherNot");
    notComponent.setPinState(1, nts::Tristate::True);
    notComponent.setLink(1, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(NotComponent, Simulate) {
    nts::Not notComponent("TestNot");
    notComponent.setPinState(1, nts::Tristate::True);
    notComponent.simulate(1);
    cr_assert_eq(notComponent.getPinState(2), nts::Tristate::False);
}

Test(NotComponent, GetPinType) {
    nts::Not NotComponent1("Not1");
    cr_assert_eq(NotComponent1.getPinType(1), "input");
    cr_assert_eq(NotComponent1.getPinType(2), "output");
}

Test(NotComponent, GetPrevValue) {
    nts::Not NotComponent1("Not1");
    cr_assert_eq(NotComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(NotComponent, GetNextValue) {
    nts::Not NotComponent1("Not1");
    cr_assert_eq(NotComponent1.getNextValue(), nts::Tristate::Undefined);
}