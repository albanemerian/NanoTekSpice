/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsTrue
*/

#include "../src/componant/True.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(TrueComponent, Constructor) {
    nts::True trueComponent("TestTrue");
    cr_assert_eq(trueComponent.getMaxPin(), 1);
    cr_assert_eq(trueComponent.getPinState(1), nts::Tristate::True);
}

Test(TrueComponent, ComputeUndefined) {
    nts::True trueComponent("TestTrue");
    cr_assert_eq(trueComponent.compute(2), nts::Tristate::Undefined);
}

Test(TrueComponent, ComputeValid) {
    nts::True trueComponent("TestTrue");
    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);
}

Test(TrueComponent, SetPinState) {
    nts::True trueComponent("TestTrue");
    trueComponent.setPinState(1, nts::Tristate::False);
    cr_assert_eq(trueComponent.getPinState(1), nts::Tristate::True);
}

Test(TrueComponent, SetLink) {
    nts::True trueComponent("TestTrue");
    nts::True otherComponent("OtherTrue");
    trueComponent.setLink(1, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(TrueComponent, Simulate) {
    nts::True trueComponent("TestTrue");
    trueComponent.simulate(1);
    cr_assert_eq(trueComponent.getPinState(1), nts::Tristate::True);
}

Test(TrueComponent, GetPinType) {
    nts::True trueComponent1("true1");
    cr_assert_eq(trueComponent1.getPinType(1), "true");
}

Test(TrueComponent, GetPrevValue) {
    nts::True trueComponent1("true1");
    cr_assert_eq(trueComponent1.getPrevValue(), nts::Tristate::True);
}

Test(TrueComponent, GetNextValue) {
    nts::True trueComponent1("true1");
    cr_assert_eq(trueComponent1.getNextValue(), nts::Tristate::True);
}
