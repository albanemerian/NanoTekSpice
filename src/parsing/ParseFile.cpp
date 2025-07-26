/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** parseFile
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "ParseFile.hpp"

static int endType(std::string str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t')
            break;
        i++;
    }
    return i;
}

static int startName(std::string str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t')
            break;
        i++;
    }
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t')) {
        i++;
    }
    return i;
}

nts::ComponentFactory &nts::ParseFile::parseFunction(ErrorParser error) {
    for (auto &chipset : error.getChipsets()) {
        std::string type = chipset.substr(0, endType(chipset));
        std::string name = chipset.substr(startName(chipset));
        if (type.empty() || name.empty())
            continue;
        std::unique_ptr<AComponent> component;
        if (type == "input")
            component = factory.createInput(name);
        else if (type == "output")
            component = factory.createOutput(name);
        else if (type == "clock")
            component = factory.createClock(name);
        else if (type == "true")
            component = factory.createTrue(name);
        else if (type == "false")
            component = factory.createFalse(name);
        else if (type == "logger")
            component = factory.createLogger(name);
        else
            component = factory.createComponent(type, name);
        factory.addComponent(name, std::move(component));
    }
    if (error.getNbLinks() % 2 != 0)
        throw ErrorParser::LexicalOrSyntacticError();
    for (int i = 0; i < error.getNbLinks(); i += 2) {
        std::string link1 = error.getLinks()[i];
        std::string link2 = error.getLinks()[i + 1];
        size_t pin1, pin2;
        size_t colon_pos = link1.find(':');
        if (colon_pos != std::string::npos) {
            pin1 = std::stoul(link1.substr(colon_pos + 1));
            link1 = link1.substr(0, colon_pos);
        }
        colon_pos = link2.find(':');
        if (colon_pos != std::string::npos) {
            pin2 = std::stoul(link2.substr(colon_pos + 1));
            link2 = link2.substr(0, colon_pos);
        }
        factory.createLink(link1, pin1, link2, pin2);
    }
    return factory;
}
