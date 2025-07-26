/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Tests 4011
*/

#include "../src/advanced-componants/Component4011.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(Component4011, Constructor) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    cr_assert_eq(nandComponent.getMaxPin(), 14);
    cr_assert_eq(nandComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(3), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(4), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(5), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(6), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(7), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(8), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(9), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(10), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(11), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(12), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(13), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(14), nts::Tristate::Undefined);
}

Test(Component4011, ComputeUndefined) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    cr_assert_eq(nandComponent.compute(1), nts::Tristate::Undefined);
}

Test(Component4011, ComputeValid) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    nandComponent.setPinState(1, nts::Tristate::False);
    nandComponent.setPinState(2, nts::Tristate::False);
    cr_assert_eq(nandComponent.compute(3), nts::Tristate::True);
}

Test(Component4011, SetPinState) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    nandComponent.setPinState(1, nts::Tristate::False);
    nandComponent.setPinState(2, nts::Tristate::False);
    nandComponent.simulate(1);
    cr_assert_eq(nandComponent.getPinState(1), nts::Tristate::False);
    cr_assert_eq(nandComponent.getPinState(2), nts::Tristate::False);
    cr_assert_eq(nandComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4011, SetLink) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    nts::Nand otherComponent("Othernand");
    nandComponent.setPinState(1, nts::Tristate::False);
    nandComponent.setPinState(2, nts::Tristate::False);
    nandComponent.simulate(1);
    nandComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(Component4011, Simulate) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    nandComponent.setPinState(1, nts::Tristate::False);
    nandComponent.setPinState(2, nts::Tristate::False);
    nandComponent.simulate(1);
    cr_assert_eq(nandComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4011, GetPinType) {
    nts::ComponentFactory factory;
    nts::Component4011 nandComponent("4011", factory);
    cr_assert_eq(nandComponent.getPinType(1), "input");
    cr_assert_eq(nandComponent.getPinType(2), "input");
    cr_assert_eq(nandComponent.getPinType(3), "output");
    cr_assert_eq(nandComponent.getPinType(4), "output");
    cr_assert_eq(nandComponent.getPinType(5), "input");
    cr_assert_eq(nandComponent.getPinType(6), "input");
    cr_assert_eq(nandComponent.getPinType(7), "input");
    cr_assert_eq(nandComponent.getPinType(8), "input");
    cr_assert_eq(nandComponent.getPinType(9), "input");
    cr_assert_eq(nandComponent.getPinType(10), "output");
    cr_assert_eq(nandComponent.getPinType(11), "output");
    cr_assert_eq(nandComponent.getPinType(12), "input");
    cr_assert_eq(nandComponent.getPinType(13), "input");
    cr_assert_eq(nandComponent.getPinType(14), "input");
}
