/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Tests 4081
*/

#include "../src/advanced-componants/Component4081.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(Component4081, Constructor) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    cr_assert_eq(andComponent.getMaxPin(), 14);
    cr_assert_eq(andComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(4), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(5), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(6), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(7), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(8), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(9), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(10), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(11), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(12), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(13), nts::Tristate::Undefined);
    cr_assert_eq(andComponent.getPinState(14), nts::Tristate::Undefined);
}

Test(Component4081, ComputeUndefined) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    cr_assert_eq(andComponent.compute(1), nts::Tristate::Undefined);
}

Test(Component4081, ComputeValid) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::True);
}

Test(Component4081, SetPinState) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    andComponent.simulate(1);
    cr_assert_eq(andComponent.getPinState(1), nts::Tristate::True);
    cr_assert_eq(andComponent.getPinState(2), nts::Tristate::True);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4081, SetLink) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    nts::And otherComponent("Otherand");
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    andComponent.simulate(1);
    andComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(Component4081, Simulate) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    andComponent.setPinState(1, nts::Tristate::True);
    andComponent.setPinState(2, nts::Tristate::True);
    andComponent.simulate(1);
    cr_assert_eq(andComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4081, GetPinType) {
    nts::ComponentFactory factory;
    nts::Component4081 andComponent("4081", factory);
    cr_assert_eq(andComponent.getPinType(1), "input");
    cr_assert_eq(andComponent.getPinType(2), "input");
    cr_assert_eq(andComponent.getPinType(3), "output");
    cr_assert_eq(andComponent.getPinType(4), "output");
    cr_assert_eq(andComponent.getPinType(5), "input");
    cr_assert_eq(andComponent.getPinType(6), "input");
    cr_assert_eq(andComponent.getPinType(7), "input");
    cr_assert_eq(andComponent.getPinType(8), "input");
    cr_assert_eq(andComponent.getPinType(9), "input");
    cr_assert_eq(andComponent.getPinType(10), "output");
    cr_assert_eq(andComponent.getPinType(11), "output");
    cr_assert_eq(andComponent.getPinType(12), "input");
    cr_assert_eq(andComponent.getPinType(13), "input");
    cr_assert_eq(andComponent.getPinType(14), "input");
}
