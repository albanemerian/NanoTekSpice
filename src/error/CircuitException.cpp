/*
** EPITECH PROJECT, 2025
** Circuit Exception
** File description:
** Handle error throwing
*/

#include "ErrorParser.hpp"

nts::ErrorParser::CircuitException::CircuitException(const std::string &message)
    : message_(message) {}

const char* nts::ErrorParser::CircuitException::what() const noexcept {
    return message_.c_str();
}

nts::ErrorParser::LexicalOrSyntacticError::LexicalOrSyntacticError() :
    CircuitException("Lexical or syntactic error in the circuit file.") {}

nts::ErrorParser::UnknownComponentType::UnknownComponentType() :
    CircuitException("Unknown component type.") {}

nts::ErrorParser::UnknownComponentName::UnknownComponentName() :
    CircuitException("Unknown component name.") {}

nts::ErrorParser::DuplicateComponentName::DuplicateComponentName() :
    CircuitException("Several components share the same name.") {}

nts::ErrorParser::NoChipsetsInCircuit::NoChipsetsInCircuit() :
    CircuitException("No chipsets in the circuit.") {}

nts::ErrorParser::UnfoundFile::UnfoundFile() :
    CircuitException("File not found.") {}

nts::ErrorParser::NotNtsFile::NotNtsFile() :
    CircuitException("File is not a .nts file.") {}

nts::ErrorParser::InvalidPinIndex::InvalidPinIndex() :
    CircuitException("Invalid connection between two pins.") {}

nts::ErrorParser::InvalidPinNumber::InvalidPinNumber() :
    CircuitException("Pin connected to a ignored pin") {}

nts::ErrorParser::PinLinkedToItself::PinLinkedToItself() :
    CircuitException("Pin linked to itself.") {}

nts::ErrorParser::ComponentWithNoName::ComponentWithNoName() :
    CircuitException("Component with no name.") {}
