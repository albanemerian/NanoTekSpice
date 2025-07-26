/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Error Parser
*/

#ifndef ERRORPARSER_HPP_
    #define ERRORPARSER_HPP_

#include <vector>
#include <iostream>
#include <exception>
#include <map>

namespace nts {
    class ErrorParser {
        public:
            class CircuitException : public std::exception {
                public:
                    explicit CircuitException(const std::string& message);
                    const char* what() const noexcept override;
                private:
                    std::string message_;
            };
            class LexicalOrSyntacticError : public CircuitException {
                public:
                    LexicalOrSyntacticError();
            };
            class UnknownComponentType : public CircuitException {
                public:
                    UnknownComponentType();
            };
            class UnknownComponentName : public CircuitException {
                public:
                    UnknownComponentName();
            };
            class DuplicateComponentName : public CircuitException {
                public:
                    DuplicateComponentName();
            };
            class NoChipsetsInCircuit : public CircuitException {
                public:
                    NoChipsetsInCircuit();
            };
            class UnfoundFile : public CircuitException {
                public:
                    UnfoundFile();
            };
            class NotNtsFile : public CircuitException {
                public:
                    NotNtsFile();
            };
            class InvalidPinIndex : public CircuitException {
                public:
                    InvalidPinIndex();
            };
            class InvalidPinNumber : public CircuitException {
                public:
                    InvalidPinNumber();
            };
            class PinLinkedToItself : public CircuitException {
                public:
                    PinLinkedToItself();
            };
            class ComponentWithNoName : public CircuitException {
                public:
                    ComponentWithNoName();
            };
            ErrorParser();
            ~ErrorParser();

            std::vector<std::string> getChipsets() const;
            std::vector<std::string> getLinks() const;
            int getNbLinks() const;

            int parseFunction(char *filename);
            std::ifstream checkFile(char const *file);
            int checkChipset(std::ifstream file);
            int checkLinks(std::ifstream file);
            int checkErroLinks(void);
        protected:
        private:
            int _nbLinks;
            std::string _file;
            std::vector<std::string> _chipsets;
            std::map<std::string, std::string> _linksAndName;
            std::vector<std::string> _links;
    };
};

#endif /* !ERRORPARSER_HPP_ */
