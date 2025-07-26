/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "../AComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"

namespace nts {
    class And : public nts::AComponent {
        public:
            And(std::string const &value);
            ~And();

            Tristate compute(std::size_t pin = 1)  override;
            Tristate computes(std::size_t pin1, std::size_t pin2, std::size_t out);
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
    };

}
#endif /* !AND_HPP_ */

