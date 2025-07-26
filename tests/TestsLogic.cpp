/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsLogic
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/logic/logic.hpp"
#include "../src/componant/Pin.hpp"


//Test and logic

Test(And_logic, basic) {
    nts::Tristate res = nts::And_logic(nts::Tristate::True, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(And_logic_two, basic) {
    nts::Tristate res = nts::And_logic(nts::Tristate::False, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(And_logic_three, basic) {
    nts::Tristate res = nts::And_logic(nts::Tristate::False, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(And_logic_four, basic) {
    nts::Tristate res = nts::And_logic(nts::Tristate::True, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(And_logic_five, basic) {
    nts::Tristate res = nts::And_logic(nts::Tristate::False, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::False);
}



// Test or logic
Test(Or_logic_true_true, basic) {
    nts::Tristate res = nts::Or_logic(nts::Tristate::True, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Or_logic_true_false, basic) {
    nts::Tristate res = nts::Or_logic(nts::Tristate::True, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Or_logic_true_undefined, basic) {
    nts::Tristate res = nts::Or_logic(nts::Tristate::True, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Or_logic_false_false, basic)
{
    nts::Tristate res = nts::Or_logic(nts::Tristate::False, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Or_logic_false_undefined, basic)
{
    nts::Tristate res = nts::Or_logic(nts::Tristate::False, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Or_logic_undefined_undefined, basic)
{
    nts::Tristate res = nts::Or_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Or_logic_undefined_true, basic)
{
    nts::Tristate res = nts::Or_logic(nts::Tristate::Undefined, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Or_logic_undefined_false, basic)
{
    nts::Tristate res = nts::Or_logic(nts::Tristate::Undefined, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}


// Test clock logic
Test(Clock_logic_undefined, basic)
{
    nts::Tristate res = nts::Clock_logic(nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Clock_logic_true, basic)
{
    nts::Tristate res = nts::Clock_logic(nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Clock_logic_false, basic)
{
    nts::Tristate res = nts::Clock_logic(nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}


// Test xor logic
Test(Xor_logic_true_true, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::True, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Xor_logic_true_false, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::True, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Xor_logic_true_undefined, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::True, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Xor_logic_false_false, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::False, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Xor_logic_false_undefined, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::False, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Xor_logic_undefined_undefined, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Xor_logic_undefined_true, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::Undefined, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Xor_logic_undefined_false, basic)
{
    nts::Tristate res = nts::Xor_logic(nts::Tristate::Undefined, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

// Test nand logic
Test(Nand_logic_true_true, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::True, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Nand_logic_true_false, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::True, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Nand_logic_true_undefined, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::True, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Nand_logic_false_false, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::False, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Nand_logic_false_undefined, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::False, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Nand_logic_undefined_undefined, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Nand_logic_undefined_true, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::Undefined, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Nand_logic_undefined_false, basic)
{
    nts::Tristate res = nts::Nand_logic(nts::Tristate::Undefined, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

// Test nor logic
Test(Nor_logic_false_false, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::False, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Nor_logic_true_false, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::True, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Nor_logic_false_true, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::False, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Nor_logic_true_true, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::True, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Nor_logic_false_undefined, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::False, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Nor_logic_undefined_false, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::Undefined, nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Nor_logic_true_undefined, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::True, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Nor_logic_undefined_true, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::Undefined, nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Nor_logic_undefined_undefined, basic)
{
    nts::Tristate res = nts::Nor_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

// Test not logic
Test(Not_logic_true, basic)
{
    nts::Tristate res = nts::Not_logic(nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Not_logic_false, basic)
{
    nts::Tristate res = nts::Not_logic(nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Not_logic_undefined, basic)
{
    nts::Tristate res = nts::Not_logic(nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::Undefined);
}


// Test true logic
Test(True_logic_any, basic)
{
    nts::Tristate res = nts::True_logic(nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(True_logic_any_false, basic)
{
    nts::Tristate res = nts::True_logic(nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(True_logic_any_undefined, basic)
{
    nts::Tristate res = nts::True_logic(nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::True);
}

// Test false logic
Test(False_logic_any, basic)
{
    nts::Tristate res = nts::False_logic(nts::Tristate::True, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(False_logic_any_false, basic)
{
    nts::Tristate res = nts::False_logic(nts::Tristate::False, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(False_logic_any_undefined, basic)
{
    nts::Tristate res = nts::False_logic(nts::Tristate::Undefined, 1);
    cr_assert_eq(res, nts::Tristate::False);
}

// Test sum logic
Test(Sum_logic_all_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Sum_logic_all_false, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::False, nts::Tristate::False, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Sum_logic_true_true_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Sum_logic_true_false_false, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::False, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Sum_logic_false_true_false, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::False, nts::Tristate::True, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Sum_logic_false_false_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::False, nts::Tristate::False, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Sum_logic_true_true_false, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Sum_logic_true_false_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::False, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Sum_logic_false_true_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::False, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Sum_logic_undefined_true_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::Undefined, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Sum_logic_true_undefined_true, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::Undefined, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Sum_logic_true_true_undefined, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::Undefined, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Sum_logic_undefined_undefined_undefined, basic)
{
    nts::Tristate res = nts::Sum_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, nts::Tristate::Undefined, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

// Test carry logic
Test(Carry_logic_all_true, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Carry_logic_all_false, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::False, nts::Tristate::False, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Carry_logic_true_false_false, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::True, nts::Tristate::False, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Carry_logic_false_true_false, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::False, nts::Tristate::True, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Carry_logic_false_false_true, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::False, nts::Tristate::False, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::False);
}

Test(Carry_logic_true_true_false, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::False, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Carry_logic_true_false_true, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::True, nts::Tristate::False, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Carry_logic_false_true_true, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::False, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::True);
}

Test(Carry_logic_undefined_true_true, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::Undefined, nts::Tristate::True, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Carry_logic_true_undefined_true, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::True, nts::Tristate::Undefined, nts::Tristate::True, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Carry_logic_true_true_undefined, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::Undefined, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}

Test(Carry_logic_undefined_undefined_undefined, basic)
{
    nts::Tristate res = nts::Carry_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, nts::Tristate::Undefined, 4);
    cr_assert_eq(res, nts::Tristate::Undefined);
}
// Test selector logic
Test(Selector_logic_true_true_true, basic)
{
    int res = nts::Selector_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(res, 9);
}

Test(Selector_logic_true_true_false, basic)
{
    int res = nts::Selector_logic(nts::Tristate::False, nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(res, 7);
}

Test(Selector_logic_true_false_true, basic)
{
    int res = nts::Selector_logic(nts::Tristate::True, nts::Tristate::False, nts::Tristate::True);
    cr_assert_eq(res, 6);
}

Test(Selector_logic_true_false_false, basic)
{
    int res = nts::Selector_logic(nts::Tristate::False, nts::Tristate::False, nts::Tristate::True);
    cr_assert_eq(res, 5);
}

Test(Selector_logic_false_true_true, basic)
{
    int res = nts::Selector_logic(nts::Tristate::True, nts::Tristate::True, nts::Tristate::False);
    cr_assert_eq(res, 4);
}

Test(Selector_logic_false_true_false, basic)
{
    int res = nts::Selector_logic(nts::Tristate::False, nts::Tristate::True, nts::Tristate::False);
    cr_assert_eq(res, 3);
}

Test(Selector_logic_false_false_true, basic)
{
    int res = nts::Selector_logic(nts::Tristate::True, nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(res, 2);
}

Test(Selector_logic_false_false_false, basic)
{
    int res = nts::Selector_logic(nts::Tristate::False, nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(res, 1);
}

Test(Selector_logic_undefined, basic)
{
    int res = nts::Selector_logic(nts::Tristate::Undefined, nts::Tristate::Undefined, nts::Tristate::Undefined);
    cr_assert_eq(res, 0);
}
