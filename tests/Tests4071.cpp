/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Tests 4071
*/

#include "../src/advanced-componants/Component4071.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(Component4071, Constructor) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    cr_assert_eq(orComponent.getMaxPin(), 14);
    cr_assert_eq(orComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(3), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(4), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(5), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(6), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(7), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(8), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(9), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(10), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(11), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(12), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(13), nts::Tristate::Undefined);
    cr_assert_eq(orComponent.getPinState(14), nts::Tristate::Undefined);
}

Test(Component4071, ComputeUndefined) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    cr_assert_eq(orComponent.compute(1), nts::Tristate::Undefined);
}

Test(Component4071, ComputeValid) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(orComponent.compute(3), nts::Tristate::True);
}

Test(Component4071, SetPinState) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::True);
    orComponent.simulate(1);
    cr_assert_eq(orComponent.getPinState(1), nts::Tristate::True);
    cr_assert_eq(orComponent.getPinState(2), nts::Tristate::True);
    cr_assert_eq(orComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4071, SetLink) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    nts::Or otherComponent("Otheror");
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::True);
    orComponent.simulate(1);
    orComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(Component4071, Simulate) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    orComponent.setPinState(1, nts::Tristate::True);
    orComponent.setPinState(2, nts::Tristate::True);
    orComponent.simulate(1);
    cr_assert_eq(orComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4071, GetPinType) {
    nts::ComponentFactory factory;
    nts::Component4071 orComponent("4071", factory);
    cr_assert_eq(orComponent.getPinType(1), "input");
    cr_assert_eq(orComponent.getPinType(2), "input");
    cr_assert_eq(orComponent.getPinType(3), "output");
    cr_assert_eq(orComponent.getPinType(4), "output");
    cr_assert_eq(orComponent.getPinType(5), "input");
    cr_assert_eq(orComponent.getPinType(6), "input");
    cr_assert_eq(orComponent.getPinType(7), "input");
    cr_assert_eq(orComponent.getPinType(8), "input");
    cr_assert_eq(orComponent.getPinType(9), "input");
    cr_assert_eq(orComponent.getPinType(10), "output");
    cr_assert_eq(orComponent.getPinType(11), "output");
    cr_assert_eq(orComponent.getPinType(12), "input");
    cr_assert_eq(orComponent.getPinType(13), "input");
    cr_assert_eq(orComponent.getPinType(14), "input");
}
