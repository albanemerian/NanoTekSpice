/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Tests 4069
*/

#include "../src/advanced-componants/Component4069.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(Component4069, Constructor) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    cr_assert_eq(notComponent.getMaxPin(), 14);
    cr_assert_eq(notComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(3), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(4), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(5), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(6), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(7), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(8), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(9), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(10), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(11), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(12), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(13), nts::Tristate::Undefined);
    cr_assert_eq(notComponent.getPinState(14), nts::Tristate::Undefined);
}

Test(Component4069, ComputeUndefined) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    cr_assert_eq(notComponent.compute(1), nts::Tristate::Undefined);
}

Test(Component4069, ComputeValid) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    notComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(notComponent.compute(2), nts::Tristate::False);
}

Test(Component4069, SetPinState) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    notComponent.setPinState(1, nts::Tristate::True);
    notComponent.simulate(1);
    cr_assert_eq(notComponent.getPinState(2), nts::Tristate::False);
}

Test(Component4069, SetLink) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    nts::Not otherComponent("OtherNot");
    notComponent.setPinState(1, nts::Tristate::True);
    notComponent.simulate(1);
    notComponent.setLink(2, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::False);
}

Test(Component4069, Simulate) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    notComponent.setPinState(1, nts::Tristate::True);
    notComponent.simulate(1);
    cr_assert_eq(notComponent.getPinState(2), nts::Tristate::False);
}

Test(Component4069, GetPinType) {
    nts::ComponentFactory factory;
    nts::Component4069 notComponent("4069", factory);
    cr_assert_eq(notComponent.getPinType(1), "input");
    cr_assert_eq(notComponent.getPinType(2), "output");
    cr_assert_eq(notComponent.getPinType(3), "input");
    cr_assert_eq(notComponent.getPinType(4), "output");
    cr_assert_eq(notComponent.getPinType(5), "input");
    cr_assert_eq(notComponent.getPinType(6), "output");
    cr_assert_eq(notComponent.getPinType(7), "input");
    cr_assert_eq(notComponent.getPinType(8), "output");
    cr_assert_eq(notComponent.getPinType(9), "input");
    cr_assert_eq(notComponent.getPinType(10), "output");
    cr_assert_eq(notComponent.getPinType(11), "input");
    cr_assert_eq(notComponent.getPinType(12), "output");
    cr_assert_eq(notComponent.getPinType(13), "input");
    cr_assert_eq(notComponent.getPinType(14), "input");
}
