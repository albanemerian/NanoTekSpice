/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsClock
*/

#include "../src/componant/Clock.hpp"
#include "../src/logic/logic.hpp"
#include "../src/componant/Pin.hpp"
#include <criterion/criterion.h>

Test(ClockComponent, Constructor) {
    nts::Clock clockComponent("TestClock");
    cr_assert_eq(clockComponent.getMaxPin(), 1);
    cr_assert_eq(clockComponent.getPinState(1), nts::Tristate::Undefined);
}

Test(ClockComponent, ComputeUndefined) {
    nts::Clock clockComponent("TestClock");
    cr_assert_eq(clockComponent.compute(2), nts::Tristate::Undefined);
}

Test(ClockComponent, ComputeValid) {
    nts::Clock clockComponent("TestClock");
    clockComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(clockComponent.compute(1), nts::Tristate::True);
}

Test(ClockComponent, SetPinState) {
    nts::Clock clockComponent("TestClock");
    clockComponent.setPinState(1, nts::Tristate::True);
    cr_assert_eq(clockComponent.getPinState(1), nts::Tristate::True);
}

Test(ClockComponent, SetLink) {
    nts::Clock clockComponent("TestClock");
    nts::Clock otherComponent("OtherClock");
    clockComponent.setPinState(1, nts::Tristate::True);
    clockComponent.setLink(1, otherComponent, 1);
    cr_assert_eq(otherComponent.getPinState(1), nts::Tristate::True);
}

Test(ClockComponent, Simulate) {
    nts::Clock clockComponent("TestClock");
    nts::Pin pin;
    clockComponent.setPinState(1, nts::Tristate::True);
    clockComponent.simulate(1);
    cr_assert_eq(clockComponent.getPinState(1), nts::Tristate::True);
    clockComponent.simulate(1);
    cr_assert_eq(clockComponent.getPinState(1), nts::Tristate::False);
}

Test(ClockComponent, GetPinType) {
    nts::Clock ClockComponent1("Clock1");
    cr_assert_eq(ClockComponent1.getPinType(1), "clock");
}

Test(ClockComponent, GetPrevValue) {
    nts::Clock ClockComponent1("Clock1");
    cr_assert_eq(ClockComponent1.getPrevValue(), nts::Tristate::Undefined);
}

Test(ClockComponent, GetNextValue) {
    nts::Clock ClockComponent1("Clock1");
    cr_assert_eq(ClockComponent1.getNextValue(), nts::Tristate::Undefined);
}
