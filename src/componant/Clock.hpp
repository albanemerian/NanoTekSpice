/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Clock : public nts::AComponent {
        public:
            Clock(std::string const &value);
            ~Clock();

            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            nts::Tristate getCurrent();
            nts::Tristate getNextValue() const override;
            nts::Tristate getPrevValue() const override;
            std::string getPinType(std::size_t pin) override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            nts::Tristate _nextValue;
            nts::Tristate _prevValue;
    };
}

#endif /* ! CLOCK_HPP_ */
