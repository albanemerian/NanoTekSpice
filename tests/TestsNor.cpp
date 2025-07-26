/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsNor
*/

#include "../src/componant/Nor.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(NorComponent, Constructor) {
    nts::Nor norComponent("TestNor");
    cr_assert_eq(norComponent.getMaxPin(), 3);
    cr_assert_eq(norComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(NorComponent, ComputeUndefined) {
    nts::Nor norComponent("TestNor");
    cr_assert_eq(norComponent.compute(1), nts::Tristate::Undefined);
}

Test(NorComponent, ComputeValid) {
    nts::Nor norComponent("TestNor");
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(norComponent.compute(3), nts::Tristate::True);
}

Test(NorComponent, SetPinState) {
    nts::Nor norComponent("TestNor");
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(norComponent.getPinState(1), nts::Tristate::False);
    cr_assert_eq(norComponent.getPinState(2), nts::Tristate::False);
    cr_assert_eq(norComponent.getPinState(3), nts::Tristate::True);
}

Test(NorComponent, SetLink) {
    nts::Nor norComponent("TestNor");
    nts::Nor otherComponent("OtherNor");
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    norComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(NorComponent, Simulate) {
    nts::Nor norComponent("TestNor");
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    norComponent.simulate(1);
    cr_assert_eq(norComponent.getPinState(3), nts::Tristate::True);
}

Test(NorComponent, GetPinType) {
    nts::Nor NorComponent1("Nor1");
    cr_assert_eq(NorComponent1.getPinType(1), "input");
    cr_assert_eq(NorComponent1.getPinType(2), "input");
    cr_assert_eq(NorComponent1.getPinType(3), "output");
}

Test(NorComponent, GetPrevValue) {
    nts::Nor NorComponent1("Nor1");
    cr_assert_eq(NorComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(NorComponent, GetNextValue) {
    nts::Nor NorComponent1("Nor1");
    cr_assert_eq(NorComponent1.getNextValue(), nts::Tristate::Undefined);
}
