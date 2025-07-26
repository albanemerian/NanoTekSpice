/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4514
*/

#ifndef COMPONENT4514_HPP_
#define COMPONENT4514_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"

namespace nts {
    class Component4514 : public nts::AComponent {
        public:
            Component4514(std::string const &value, ComponentFactory &factory);
            ~Component4514();

            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            Tristate compute(std::size_t pin = 1)  override;
            void setPinState(std::size_t pin, nts::Tristate state) override;
            std::string getPinType(std::size_t pin) override;
            protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            std::string _name;
            ComponentFactory &_factory;
            nts::Not _notIn0;
            nts::Nor _and0_0;
            nts::Nor _and0_1;

            nts::Not _notIn1;
            nts::Nor _and1_0;
            nts::Nor _and1_1;

            nts::Not _notIn2;
            nts::Nor _and2_0;
            nts::Nor _and2_1;

            nts::Not _notIn3;
            nts::Nor _and3_0;
            nts::Nor _and3_1;

            nts::Not _notStrobe;
            nts::Not _notInhibit;

            nts::FlipFlop _flipflop1;
            nts::FlipFlop _flipflop2;
            nts::FlipFlop _flipflop3;
            nts::FlipFlop _flipflop4;

            nts::Nor _andFlip1;
            nts::Nor _andFlip2;
            nts::Nor _andFlip3;
            nts::Nor _andFlip4;
            nts::Nor _andFlip5;
            nts::Nor _andFlip6;
            nts::Nor _andFlip7;
            nts::Nor _andFlip8;

            nts::AndThree _andOutput0; //douvble nand component
            nts::AndThree _andOutput1;
            nts::AndThree _andOutput2;
            nts::AndThree _andOutput3;
            nts::AndThree _andOutput4;
            nts::AndThree _andOutput5;
            nts::AndThree _andOutput6;
            nts::AndThree _andOutput7;
            nts::AndThree _andOutput8;
            nts::AndThree _andOutput9;
            nts::AndThree _andOutput10;
            nts::AndThree _andOutput11;
            nts::AndThree _andOutput12;
            nts::AndThree _andOutput13;
            nts::AndThree _andOutput14;
            nts::AndThree _andOutput15;

            nts::Not _notOutput0;
            nts::Not _notOutput1;
            nts::Not _notOutput2;
            nts::Not _notOutput3;
            nts::Not _notOutput4;
            nts::Not _notOutput5;
            nts::Not _notOutput6;
            nts::Not _notOutput7;
            nts::Not _notOutput8;
            nts::Not _notOutput9;
            nts::Not _notOutput10;
            nts::Not _notOutput11;
            nts::Not _notOutput12;
            nts::Not _notOutput13;
            nts::Not _notOutput14;
            nts::Not _notOutput15;
};
}

#endif /* !COMPONENT4514_HPP_ */
