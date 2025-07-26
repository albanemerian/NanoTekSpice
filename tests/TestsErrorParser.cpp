/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** TestsErrorParser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/error/ErrorParser.hpp"

Test(ErrorParser_checkFile_invalid, basic)
{
    nts::ErrorParser error;
    cr_redirect_stderr();
    cr_assert_throw(error.checkFile("./tests/invalid_file.nts"), nts::ErrorParser::UnfoundFile);
}

Test(ErrorParser_parseFunction_invalid, basic)
{
    nts::ErrorParser error;
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction((char *)"./tests/invalid_file.nts"), nts::ErrorParser::UnfoundFile);
}

Test(ErrorParser_getChipsets, basic)
{
    nts::ErrorParser error;
    std::vector<std::string> chipsets = error.getChipsets();
    cr_assert(chipsets.empty());
}

Test(ErrorParser_getLinks, basic)
{
    nts::ErrorParser error;
    std::vector<std::string> links = error.getLinks();
    cr_assert(links.empty());
}

Test(ErrorParser_checkFile_valid, basic)
{
    nts::ErrorParser error;
    std::ifstream file = error.checkFile("./tests/FileValid.nts");
    cr_assert(file.is_open());
    file.close();
}

Test(ErrorParser_checkChipset_valid, basic)
{
    nts::ErrorParser error;
    int res = error.checkChipset(error.checkFile("./tests/FileValid.nts"));
    cr_assert_eq(res, 0);
}

Test(ErrorParser_parseFunction_valid, basic)
{
    nts::ErrorParser error;
    int res = error.parseFunction((char *)"./tests/FileValid.nts");
    cr_assert_eq(res, 0);
}

Test(ErrorParser_checkFile_missing_chipsets, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/miss_chipsets_section.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::LexicalOrSyntacticError);
}

