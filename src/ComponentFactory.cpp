/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "componant/Input.hpp"
#include "componant/Output.hpp"
#include "componant/Pin.hpp"
#include <algorithm>
#include <set>


std::unique_ptr<nts::AComponent> nts::ComponentFactory::createInput(const std::string &value) {
    return std::make_unique<Input>(value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createOutput(const std::string &value) {
    return std::make_unique<Output>(value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createClock(const std::string &value) {
    return std::make_unique<Clock>(value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createTrue(const std::string &value) {
    return std::make_unique<True>(value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createFalse(const std::string &value) {
    return std::make_unique<False>(value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createLogger(const std::string &value) {
    return std::make_unique<Logger>(value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createComponent(const std::string &type, const std::string &value) {
    if (type == "and")
        return std::make_unique<And>(value);
    if (type == "or")
        return std::make_unique<Or>(value);
    if (type == "xor")
        return std::make_unique<Xor>(value);
    if (type == "not")
        return std::make_unique<Not>(value);
    if (type == "4001")
        return std::make_unique<Component4001>(value, *this);
    if (type == "4011")
        return std::make_unique<Component4011>(value, *this);
    if (type == "4030")
        return std::make_unique<Component4030>(value, *this);
    if (type == "4069")
        return std::make_unique<Component4069>(value, *this);
    if (type == "4071")
        return std::make_unique<Component4071>(value, *this);
    if (type == "4081")
        return std::make_unique<Component4081>(value, *this);
    if (type == "4008")
        return std::make_unique<Component4008>(value, *this);
    if (type == "4801")
        return std::make_unique<Component4801>(value, *this);
    if (type == "4013")
        return std::make_unique<Component4013>(value, *this);
    if (type == "4094")
        return std::make_unique<Component4094>(value, *this);
    if (type == "4514")
        return std::make_unique<Component4514>(value, *this);
    if (type == "4017")
        return std::make_unique<Component4017>(value, *this);
    if (type == "4040")
        return std::make_unique<Component4040>(value, *this);
    if (type == "4512")
        return std::make_unique<Component4512>(value, *this);
    throw ErrorParser::UnknownComponentType();
}

void nts::ComponentFactory::addComponent(const std::string &name, std::unique_ptr<AComponent> component) {
    components[name] = std::move(component);
    componentOrder.push_back(name);
}

void nts::ComponentFactory::createLink(const std::string &comp1, size_t pin1, const std::string &comp2, size_t pin2) {
    if (components[comp1].get()->getMaxPin() < pin1 || pin1 <= 0)
        throw ErrorParser::InvalidPinIndex();
    if (components[comp2].get()->getMaxPin() < pin2 || pin2 <= 0)
        throw ErrorParser::InvalidPinIndex();
    components[comp1]->setLink(pin1, *components[comp2], pin2);
    components[comp2]->setLink(pin2, *components[comp1], pin1);
    links.push_back({{comp1, pin1}, {comp2, pin2}});
    links.push_back({{comp2, pin2}, {comp1, pin1}});
}

void nts::ComponentFactory::simulate() {
    tick++;

    std::set<std::pair<std::pair<std::string, size_t>, nts::Tristate>> processedUpdates;
    while (!pendingUpdates.empty()) {
        auto [pinInfo, value] = pendingUpdates.front();
        pendingUpdates.pop();
        const auto &name = pinInfo.first;
        const auto &pin = pinInfo.second;
        if (processedUpdates.find({{name, pin}, value}) != processedUpdates.end()) {
            continue;
        }
        components[name]->setPinState(pin, value);
        updateLinkedPinState(name, pin, value);
        processedUpdates.insert({{name, pin}, value});
    }
    for (const auto &name : componentOrder) {
        components[name]->simulate(tick);
    }
    for (const auto &link : links) {
        const auto &comp1 = link.first.first;
        auto &pin1 = link.first.second;
        const auto &comp2 = link.second.first;
        auto &pin2 = link.second.second;
        if (dynamic_cast<Output*>(components[comp1].get())) {
            nts::Tristate state = components[comp2]->compute(pin2);
            components[comp1]->setPinState(pin1, state);
        }
        if (components[comp1]->getPinType(pin1) == "output" && components[comp2]->getPinType(pin2) != "clock") {
            nts::Tristate state = components[comp1]->compute(pin1);
            components[comp2]->setPinState(pin2, state);
        }
        if (components[comp2]->getPinType(pin2) == "output" && components[comp1]->getPinType(pin1) != "clock") {
            nts::Tristate state = components[comp2]->compute(pin2);
            components[comp1]->setPinState(pin1, state);
        }
    }
}

void nts::ComponentFactory::display() {

    std::cout << "tick: " << tick << std::endl;


    for (const auto &link : links) {
        const auto &comp1 = link.first.first;
        const auto &pin1 = link.first.second;
        const auto &comp2 = link.second.first;
        const auto &pin2 = link.second.second;
        if (dynamic_cast<Output*>(components[comp1].get())) {
            nts::Tristate state = components[comp2]->compute(pin2);
            components[comp1]->setPinState(pin1, state);
        }
    }
    std::cout << "input(s):" << std::endl;
    std::vector<std::string> inputKeys;
    for (const auto &name : componentOrder) {
        if (dynamic_cast<Input*>(components.at(name).get()) || dynamic_cast<Clock*>(components.at(name).get())) {
            inputKeys.push_back(name);
        }
    }
    std::sort(inputKeys.begin(), inputKeys.end());
    for (const auto &name : inputKeys) {
        std::cout << "  " << name << ": " << components.at(name)->getPinState(1) << std::endl;
    }

    std::cout << "output(s):" << std::endl;
    std::vector<std::string> outputKeys;
    for (const auto &name : componentOrder) {
        if (dynamic_cast<Output*>(components.at(name).get())) {
            outputKeys.push_back(name);
        }
    }
    std::sort(outputKeys.begin(), outputKeys.end());
    for (const auto &name : outputKeys) {
        std::cout << "  " << name << ": " << components.at(name)->getPinState(1) << std::endl;
    }
}

void nts::ComponentFactory::setValue(const std::string &name, nts::Tristate value) {
    if (components.find(name) == components.end()) {
        std::cout << "Component not found" << std::endl;
        return;
    }
    if (value != nts::Tristate::False && value != nts::Tristate::True && value != nts::Tristate::Undefined) {
        std::cout << "Invalid value" << std::endl;
        return;
    }
    if (dynamic_cast<Input*>(components[name].get()) == nullptr && dynamic_cast<Clock*>(components[name].get()) == nullptr) {
        std::cout << "Component is not an input or a Clock" << std::endl;
        return;
    }
    pendingUpdates.push({{name, 1}, value}); // ajouter le pin a modifier a une liste
}

void nts::ComponentFactory::updateLinkedPinState(const std::string &name, size_t pin, nts::Tristate value) {
    for (const auto &link : links) {
        if (link.first.first == name && link.first.second == pin) {
            const auto &linkedComp = link.second.first;
            const auto &linkedPin = link.second.second;
            if (components.find(linkedComp) != components.end()) {
                components[linkedComp]->setPinState(linkedPin, value);
            }
        }
    }
}


