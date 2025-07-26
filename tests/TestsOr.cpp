/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestOr
*/


#include "../src/componant/Or.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(OrComponent, Constructor) {
    nts::Or orComponent("or1");
    cr_assert_eq(orComponent.getMaxPin(), 3);
    cr_assert_eq(orComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(OrComponent, Compute) {
    nts::Or orComponent("or1");
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(orComponent.compute(3), nts::Tristate::True);
}

Test(OrComponent, SetPinState) {
    nts::Or orComponent("or1");
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(orComponent.getPinState(1), nts::Tristate::True);
    cr_assert_eq(orComponent.getPinState(2), nts::Tristate::False);
    cr_assert_eq(orComponent.getPinState(3), nts::Tristate::True);
}

Test(OrComponent, SetLink) {
    nts::Or orComponent1("or1");
    nts::Or orComponent2("or2");
    orComponent1.setPinState(1, nts::Tristate::True);
    orComponent1.setPinState(2, nts::Tristate::False);
    orComponent1.setLink(3, orComponent2, 1);
    cr_assert_eq(orComponent2.getPinState(1), nts::Tristate::True);
}

Test(OrComponent, Simulate) {
    nts::Or orComponent("or1");
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::False);
    orComponent.simulate(1);
    cr_assert_eq(orComponent.getPinState(3), nts::Tristate::True);
}

Test(OrComponentElse, Simulate) {
    nts::Or orComponent("or1");
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::False);
    orComponent.compute(5);
    // cr_assert_eq(orComponent.getPinState(3), nts::Tristate::True);
}

Test(OrComponent, GetPinType) {
    nts::Or OrComponent1("Or1");
    cr_assert_eq(OrComponent1.getPinType(1), "input");
    cr_assert_eq(OrComponent1.getPinType(2), "input");
    cr_assert_eq(OrComponent1.getPinType(3), "output");
}

Test(OrComponent, GetPrevValue) {
    nts::Or OrComponent1("Or1");
    cr_assert_eq(OrComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(OrComponent, GetNextValue) {
    nts::Or OrComponent1("Or1");
    cr_assert_eq(OrComponent1.getNextValue(), nts::Tristate::Undefined);
}
