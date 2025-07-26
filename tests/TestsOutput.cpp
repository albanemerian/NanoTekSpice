/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsOutput
*/

#include "../src/componant/Output.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(OutputComponent, Constructor) {
    nts::Output outputComponent("TestOutput");
    cr_assert_eq(outputComponent.getMaxPin(), 1);
    cr_assert_eq(outputComponent.getPinState(1), nts::Tristate::Undefined);
}

Test(OutputComponent, ComputeUndefined) {
    nts::Output outputComponent("TestOutput");
    cr_assert_eq(outputComponent.compute(2), nts::Tristate::Undefined);
}

Test(OutputComponent, ComputeValid) {
    nts::Output outputComponent("TestOutput");
    outputComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::True);
}

Test(OutputComponent, SetPinState) {
    nts::Output outputComponent("TestOutput");
    outputComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(outputComponent.getPinState(1), nts::Tristate::True);
}

Test(OutputComponent, SetLink) {
    nts::Output outputComponent("TestOutput");
    nts::Output otherComponent("OtherOutput");
    outputComponent.setPinState(1, nts::Tristate::True);
    outputComponent.setLink(1, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(OutputComponent, Simulate) {
    nts::Output outputComponent("TestOutput");
    outputComponent.simulate(1);
    cr_assert_eq(outputComponent.getPinState(1), nts::Tristate::Undefined);
}

Test(OutputComponent, GetPinType) {
    nts::Output OutputComponent1("Output1");
    cr_assert_eq(OutputComponent1.getPinType(1), "output");
}

Test(OutputComponent, GetPrevValue) {
    nts::Output OutputComponent1("Output1");
    cr_assert_eq(OutputComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(OutputComponent, GetNextValue) {
    nts::Output OutputComponent1("Output1");
    cr_assert_eq(OutputComponent1.getNextValue(), nts::Tristate::Undefined);
}
