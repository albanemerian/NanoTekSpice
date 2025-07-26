/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsInputs
*/

#include "../src/componant/Input.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(InputComponent, Constructor) {
    nts::Input inputComponent("TestInput");
    cr_assert_eq(inputComponent.getMaxPin(), 1);
    cr_assert_eq(inputComponent.getPinState(1), nts::Tristate::Undefined);
}

Test(InputComponent, ComputeUndefined) {
    nts::Input inputComponent("TestInput");
    cr_assert_eq(inputComponent.compute(2), nts::Tristate::Undefined);
}

Test(InputComponent, ComputeValid) {
    nts::Input inputComponent("TestInput");
    inputComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(inputComponent.compute(1), nts::Tristate::True);
}

Test(InputComponent, SetPinState) {
    nts::Input inputComponent("TestInput");
    inputComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(inputComponent.getPinState(1), nts::Tristate::True);
}

Test(InputComponent, SetLink) {
    nts::Input inputComponent("TestInput");
    nts::Input otherComponent("OtherInput");
    inputComponent.setPinState(1, nts::Tristate::True);
    inputComponent.setLink(1, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(InputComponent, Simulate) {
    nts::Input inputComponent("TestInput");
    inputComponent.simulate(1);
    cr_assert_eq(inputComponent.getPinState(1), nts::Tristate::Undefined);
}

Test(InputComponent, GetPinType) {
    nts::Input InputComponent1("Input1");
    cr_assert_eq(InputComponent1.getPinType(1), "input");
}

Test(InputComponent, GetPrevValue) {
    nts::Input InputComponent1("Input1");
    cr_assert_eq(InputComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(InputComponent, GetNextValue) {
    nts::Input InputComponent1("Input1");
    cr_assert_eq(InputComponent1.getNextValue(), nts::Tristate::Undefined);
}
