/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsFalse
*/

#include "../src/componant/False.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(FalseComponent, Constructor) {
    nts::False falseComponent("TestFalse");
    cr_assert_eq(falseComponent.getMaxPin(), 1);
    cr_assert_eq(falseComponent.getPinState(1), nts::Tristate::False);
}

Test(FalseComponent, ComputeUndefined) {
    nts::False falseComponent("TestFalse");
    cr_assert_eq(falseComponent.compute(2), nts::Tristate::Undefined);
}

Test(FalseComponent, ComputeValid) {
    nts::False falseComponent("TestFalse");
    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);
}

Test(FalseComponent, SetPinState) {
    nts::False falseComponent("TestFalse");
    falseComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(falseComponent.getPinState(1), nts::Tristate::False);
}

Test(FalseComponent, SetLink) {
    nts::False falseComponent("TestFalse");
    nts::False otherComponent("OtherFalse");
    falseComponent.setLink(1, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::False);
}

Test(FalseComponent, Simulate) {
    nts::False falseComponent("TestFalse");
    falseComponent.simulate(1);
    cr_assert_eq(falseComponent.getPinState(1), nts::Tristate::False);
}

Test(FalseComponent, GetPinType) {
    nts::False falseComponent1("false1");
    cr_assert_eq(falseComponent1.getPinType(1), "false");
}

Test(FalseComponent, GetPrevValue) {
    nts::False falseComponent1("false1");
    cr_assert_eq(falseComponent1.getPrevValue(), nts::Tristate::False);
}

Test(FalseComponent, GetNextValue) {
    nts::False falseComponent1("false1");
    cr_assert_eq(falseComponent1.getNextValue(), nts::Tristate::False);
}
