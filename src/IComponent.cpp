/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** IComponent
*/


#include "IComponent.hpp"

std::ostream &operator<<(std::ostream &os, nts::Tristate state) {
    switch (state) {
        case nts::Tristate::True:
            os << "1";
            break;
        case nts::Tristate::False:
            os << "0";
            break;
        case nts::Tristate::Undefined:
            os << "U";
            break;
    }
    return os;
}
