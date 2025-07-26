/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** LoopFunction
*/

#include <iostream>
#include <signal.h>
#include <string.h>
#include <thread>
#include <atomic>
#include <sys/types.h>
#include <sys/wait.h>
#include "LoopFunction.hpp"


std::atomic<bool> sigint_received(false);

void handle_sigint(int signal) {
    if (signal == SIGINT) {
        sigint_received.store(true);
    }
}

void nts::LoopFunction::loop_input(ComponentFactory &factory) {
    signal(SIGINT, handle_sigint);

    while (1)  {
        factory.simulate();
        factory.display();
        if (sigint_received.load()) {
            sigint_received.store(false);
            break;
        }
    }
    return;
}

void nts::LoopFunction::handleInput(const std::string &input, ComponentFactory &factory) {
    int value = -1;
    size_t equal_pos = input.find('=');

    if (input == "display") {
        factory.display();
    } else if (input == "simulate") {
        factory.simulate();
    } else if (input == "exit") {
        exit(0);
    } else if (input == "loop") {
        loop_input(factory);
    } else if (equal_pos != std::string::npos) {
        std::string name = input.substr(0, equal_pos);
        try {
            if (input.substr(equal_pos + 1) == "U")
                value = -1;
            else
                value = std::stoi(input.substr(equal_pos + 1));
            factory.setValue(name, static_cast<nts::Tristate>(value));
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
        } catch (const std::out_of_range &e) {
            std::cerr << "Out of range: " << e.what() << std::endl;
        }
        factory.setValue(name, static_cast<nts::Tristate>(value));
    } else if (input == "D") {
        factory.display();
    } else if (input == "S") {
        factory.simulate();
    } else if (input == "clear") {
        system("clear");
    }
}

void nts::LoopFunction::loop_function(ComponentFactory &factory) {
    std::string input;

    while (1) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            break;
        }
        handleInput(input, factory);
    }
}
