/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Counter
*/

#ifndef COUNTER_HPP_
#define COUNTER_HPP_

#include "../AComponent.hpp"

namespace nts {

    class Counter : public nts::AComponent {
        public:
            Counter(std::string const &value);
            ~Counter();

            Tristate computes(std::size_t pin1, std::size_t pin3, std::size_t out, std::size_t outb);
            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            nts::Tristate getNextValue() const override;
            std::string getPinType(std::size_t pin) override;
            nts::Tristate getPrevValue() const override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            std::string _name;
            size_t MAX_PIN;
    };

}

#endif /* ! COUNTER_HPP_ */
