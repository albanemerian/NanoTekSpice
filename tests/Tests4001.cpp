/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Tests 4001
*/

#include "../src/advanced-componants/Component4001.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(Component4001, Constructor) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    cr_assert_eq(norComponent.getMaxPin(), 14);
    cr_assert_eq(norComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(3), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(4), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(5), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(6), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(7), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(8), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(9), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(10), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(11), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(12), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(13), nts::Tristate::Undefined);
    cr_assert_eq(norComponent.getPinState(14), nts::Tristate::Undefined);
}

Test(Component4001, ComputeUndefined) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    cr_assert_eq(norComponent.compute(1), nts::Tristate::Undefined);
}

Test(Component4001, ComputeValid) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(norComponent.compute(3), nts::Tristate::True);
}

Test(Component4001, SetPinState) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    norComponent.simulate(1);
    cr_assert_eq(norComponent.getPinState(1), nts::Tristate::False);
    cr_assert_eq(norComponent.getPinState(2), nts::Tristate::False);
    cr_assert_eq(norComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4001, SetLink) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    nts::Nor otherComponent("OtherNor");
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    norComponent.simulate(1);
    norComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(Component4001, Simulate) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    norComponent.setPinState(1, nts::Tristate::False);
    norComponent.setPinState(2, nts::Tristate::False);
    norComponent.simulate(1);
    cr_assert_eq(norComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4001, GetPinType) {
    nts::ComponentFactory factory;
    nts::Component4001 norComponent("4001", factory);
    cr_assert_eq(norComponent.getPinType(1), "input");
    cr_assert_eq(norComponent.getPinType(2), "input");
    cr_assert_eq(norComponent.getPinType(3), "output");
    cr_assert_eq(norComponent.getPinType(4), "output");
    cr_assert_eq(norComponent.getPinType(5), "input");
    cr_assert_eq(norComponent.getPinType(6), "input");
    cr_assert_eq(norComponent.getPinType(7), "input");
    cr_assert_eq(norComponent.getPinType(8), "input");
    cr_assert_eq(norComponent.getPinType(9), "input");
    cr_assert_eq(norComponent.getPinType(10), "output");
    cr_assert_eq(norComponent.getPinType(11), "output");
    cr_assert_eq(norComponent.getPinType(12), "input");
    cr_assert_eq(norComponent.getPinType(13), "input");
    cr_assert_eq(norComponent.getPinType(14), "input");
}
