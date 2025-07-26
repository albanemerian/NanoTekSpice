/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsNand
*/

#include "../src/componant/Nand.hpp"
#include "../src/logic/logic.hpp"
#include <criterion/criterion.h>

Test(NandComponent, Constructor) {
    nts::Nand nandComponent("TestNand");
    cr_assert_eq(nandComponent.getMaxPin(), 3);
    cr_assert_eq(nandComponent.getPinState(1), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(2), nts::Tristate::Undefined);
    cr_assert_eq(nandComponent.getPinState(3), nts::Tristate::Undefined);
}

Test(NandComponent, ComputeUndefined) {
    nts::Nand nandComponent("TestNand");
    cr_assert_eq(nandComponent.compute(1), nts::Tristate::Undefined);
}

Test(NandComponent, ComputeValid) {
    nts::Nand nandComponent("TestNand");
    nandComponent.setPinState(1, nts::Tristate::True);
    nandComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(nandComponent.compute(3), nts::Tristate::False);
}

Test(NandComponent, SetPinState) {
    nts::Nand nandComponent("TestNand");
    nandComponent.setPinState(1, nts::Tristate::True);
    nandComponent.setPinState(2, nts::Tristate::True);
    cr_assert_eq(nandComponent.getPinState(1), nts::Tristate::True);
    cr_assert_eq(nandComponent.getPinState(2), nts::Tristate::True);
    cr_assert_eq(nandComponent.getPinState(3), nts::Tristate::False);
}

Test(NandComponent, SetLink) {
    nts::Nand nandComponent("TestNand");
    nts::Nand otherComponent("OtherNand");
    nandComponent.setPinState(1, nts::Tristate::True);
    nandComponent.setPinState(2, nts::Tristate::True);
    nandComponent.setLink(3, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::False);
}

Test(NandComponent, Simulate) {
    nts::Nand nandComponent("TestNand");
    nandComponent.setPinState(1, nts::Tristate::True);
    nandComponent.setPinState(2, nts::Tristate::True);
    nandComponent.simulate(1);
    cr_assert_eq(nandComponent.getPinState(3), nts::Tristate::False);
}

Test(NandComponent, GetPinType) {
    nts::Nand NandComponent1("Nand1");
    cr_assert_eq(NandComponent1.getPinType(1), "input");
    cr_assert_eq(NandComponent1.getPinType(2), "input");
    cr_assert_eq(NandComponent1.getPinType(3), "output");
}

Test(NandComponent, GetPrevValue) {
    nts::Nand NandComponent1("Nand1");
    cr_assert_eq(NandComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(NandComponent, GetNextValue) {
    nts::Nand NandComponent1("Nand1");
    cr_assert_eq(NandComponent1.getNextValue(), nts::Tristate::Undefined);
}