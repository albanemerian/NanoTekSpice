/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** AndThree
*/

#ifndef ANDTHREE_HPP_
#define ANDTHREE_HPP_

#include "../AComponent.hpp"
#include "Nand.hpp"

namespace nts {
    class AndThree : public nts::AComponent {
        public:
            AndThree(std::string const &value);
            ~AndThree();

            Tristate compute(std::size_t pin = 1)  override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)  override;
            void simulate(std::size_t tick)  override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            std::string getPinType(size_t pin) override;
            nts::Tristate getNextValue() const override;
            nts::Tristate getPrevValue() const override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            std::string _name;
            nts::Nand _Nand;
    };

}

#endif /* !ANDTHREE_HPP_ */
