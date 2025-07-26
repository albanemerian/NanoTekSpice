/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Tests 4030
*/

#include "../src/advanced-componants/Component4030.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(Component4030, Constructor) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    cr_assert_eq(xorComponent.getMaxPin(), 14);
    cr_assert_eq(xorComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(3), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(4), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(5), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(6), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(7), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(8), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(9), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(10), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(11), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(12), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(13), nts::Tristate::Undefined);
    cr_assert_eq(xorComponent.getPinState(14), nts::Tristate::Undefined);
}

Test(Component4030, ComputeUndefined) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    cr_assert_eq(xorComponent.compute(1), nts::Tristate::Undefined);
}

Test(Component4030, ComputeValid) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    xorComponent.setPinState(1, nts::Tristate::False);
    xorComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(xorComponent.compute(3), nts::Tristate::True);
}

Test(Component4030, SetPinState) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    xorComponent.setPinState(1, nts::Tristate::False);
    xorComponent.setPinState(2, nts::Tristate::True);
    xorComponent.simulate(1);
    cr_assert_eq(xorComponent.getPinState(1), nts::Tristate::False);
    cr_assert_eq(xorComponent.getPinState(2), nts::Tristate::True);
    cr_assert_eq(xorComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4030, SetLink) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    nts::Xor otherComponent("Otherxor");
    xorComponent.setPinState(1, nts::Tristate::False);
    xorComponent.setPinState(2, nts::Tristate::True);
    xorComponent.simulate(1);
    xorComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(Component4030, Simulate) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    xorComponent.setPinState(1, nts::Tristate::False);
    xorComponent.setPinState(2, nts::Tristate::True);
    xorComponent.simulate(1);
    cr_assert_eq(xorComponent.getPinState(3), nts::Tristate::True);
}

Test(Component4030, GetPinType) {
    nts::ComponentFactory factory;
    nts::Component4030 xorComponent("4030", factory);
    cr_assert_eq(xorComponent.getPinType(1), "input");
    cr_assert_eq(xorComponent.getPinType(2), "input");
    cr_assert_eq(xorComponent.getPinType(3), "output");
    cr_assert_eq(xorComponent.getPinType(4), "output");
    cr_assert_eq(xorComponent.getPinType(5), "input");
    cr_assert_eq(xorComponent.getPinType(6), "input");
    cr_assert_eq(xorComponent.getPinType(7), "input");
    cr_assert_eq(xorComponent.getPinType(8), "input");
    cr_assert_eq(xorComponent.getPinType(9), "input");
    cr_assert_eq(xorComponent.getPinType(10), "output");
    cr_assert_eq(xorComponent.getPinType(11), "output");
    cr_assert_eq(xorComponent.getPinType(12), "input");
    cr_assert_eq(xorComponent.getPinType(13), "input");
    cr_assert_eq(xorComponent.getPinType(14), "input");
}
