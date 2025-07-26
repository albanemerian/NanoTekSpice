/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <iostream>

namespace nts {

    class Pin {
        public:
            std::string _name;
            std::string _type;
            nts::Tristate _value;
    };

}
#endif /* !PIN_HPP_ */
