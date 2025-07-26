/*
** EPITECH PROJECT, 2025
** Algorithm Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/error/ErrorParser.hpp"

Test(validChipsets, int)
{
    nts::ErrorParser error;
    int res = error.checkChipset(error.checkFile("./tests/FileValid.nts"));

    cr_assert_eq(res, 0);
}

Test(validExtension, basic)
{
    nts::ErrorParser error;
    cr_redirect_stderr();
    int res = error.parseFunction((char *)"./tests/FileValid.nts");
    cr_assert_eq(res, 0);
}

Test(validFile, basic)
{
    nts::ErrorParser error;
    std::ifstream file = error.checkFile("./tests/FileNoChipset.nts");
    cr_assert(file.is_open());
    file.close();
}

Test(ErrorParser_destructor, basic)
{
    nts::ErrorParser *error = new nts::ErrorParser();
    error->getChipsets().push_back("test");
    error->getLinks().push_back("test:1");

    delete error;
    cr_assert_eq(1, 1);
}

Test(checkLinks_empty_line, basic)
{
    nts::ErrorParser error;
    std::ofstream tempFile("temp.nts");
    tempFile << ".links:\n\n";
    tempFile.close();

    int result = error.checkLinks(error.checkFile("temp.nts"));
    cr_assert_eq(result, 0);
    std::remove("temp.nts");
}

Test(ErrorParser_destructor_empty_vectors, basic)
{
    nts::ErrorParser *error = new nts::ErrorParser();
    delete error;
    cr_assert_eq(1, 1);
}

Test(Error_Exeptions_NotFound, basic)
{
    nts::ErrorParser error;
    cr_redirect_stderr();
    cr_assert_throw(error.checkFile("test"), nts::ErrorParser::UnfoundFile);
}

Test(Error_Exeptions_Not_Nts, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/tester.sh");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::NotNtsFile);
}

Test(Error_Exeptions_Unkown_Comp, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/unknown_name.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_invalid_chipset_1, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_chipsets_section_content_1.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::ComponentWithNoName);
}

Test(Error_invalid_chipset_2, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_chipsets_section_content_2.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_Invalid_Link_three, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_links_section_content_3.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_Invalid_Link_fiur, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_links_section_content_4.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_Invalid_Value_One, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_value_1.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_Invalid_Format_One, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_value_format_1.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_Invalid_Format_Two, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_value_format_2.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentName);
}

Test(Error_Lexical, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/miss_chipsets_section.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::LexicalOrSyntacticError);
}

Test(Error_Component_Type, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/unkown_type.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::UnknownComponentType);
}

Test(CircuitException_test, basic)
{
    std::string testMessage = "Test exception message";
    try {
        throw nts::ErrorParser::CircuitException(testMessage);
    } catch (const nts::ErrorParser::CircuitException &e) {
        cr_assert_str_eq(e.what(), testMessage.c_str(), "Exception message does not match");
    }
}

Test(CircuitException_what, basic)
{
    nts::ErrorParser::CircuitException ex("Test message");
    cr_assert_str_eq(ex.what(), "Test message");
}

Test(LexicalOrSyntacticError_what, basic)
{
    nts::ErrorParser::LexicalOrSyntacticError ex;
    cr_assert_str_eq(ex.what(), "Lexical or syntactic error in the circuit file.");
}

Test(UnknownComponentType_what, basic)
{
    nts::ErrorParser::UnknownComponentType ex;
    cr_assert_str_eq(ex.what(), "Unknown component type.");
}

Test(UnknownComponentName_what, basic)
{
    nts::ErrorParser::UnknownComponentName ex;
    cr_assert_str_eq(ex.what(), "Unknown component name.");
}

Test(DuplicateComponentName_what, basic)
{
    nts::ErrorParser::DuplicateComponentName ex;
    cr_assert_str_eq(ex.what(), "Several components share the same name.");
}

Test(NoChipsetsInCircuit_what, basic)
{
    nts::ErrorParser::NoChipsetsInCircuit ex;
    cr_assert_str_eq(ex.what(), "No chipsets in the circuit.");
}

Test(UnfoundFile_what, basic)
{
    nts::ErrorParser::UnfoundFile ex;
    cr_assert_str_eq(ex.what(), "File not found.");
}

Test(NotNtsFile_what, basic)
{
    nts::ErrorParser::NotNtsFile ex;
    cr_assert_str_eq(ex.what(), "File is not a .nts file.");
}
Test(InvalidPinIndex_what, basic)
{
    nts::ErrorParser::InvalidPinIndex ex;
    cr_assert_str_eq(ex.what(), "Invalid connection between two pins.");
}

Test(InvalidPinNumber_what, basic)
{
    nts::ErrorParser::InvalidPinNumber ex;
    cr_assert_str_eq(ex.what(), "Pin connected to a ignored pin");
}

Test(PinLinkedToItself_what, basic)
{
    nts::ErrorParser::PinLinkedToItself ex;
    cr_assert_str_eq(ex.what(), "Pin linked to itself.");
}

Test(ComponentWithNoName_what, basic)
{
    nts::ErrorParser::ComponentWithNoName ex;
    cr_assert_str_eq(ex.what(), "Component with no name.");
}

Test(Error_Ignored_pin, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_pin_3.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::InvalidPinNumber);
}

Test(Error_Component_With_No_Name, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/invalid_chipsets_section_content_1.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::ComponentWithNoName);
}

Test(Error_Pin_Linked_To_Itself, basic)
{
    nts::ErrorParser error;
    char *file = strdup("./tests/test-invalid/link_input_to_itself.nts");
    cr_redirect_stderr();
    cr_assert_throw(error.parseFunction(file), nts::ErrorParser::PinLinkedToItself);
}
