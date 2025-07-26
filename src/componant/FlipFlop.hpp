/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Flip Flop
*/

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "../AComponent.hpp"
#include "Clock.hpp"

namespace nts {

    class FlipFlop : public nts::AComponent {
        public:
            FlipFlop(std::string const &value);
            ~FlipFlop();

            Tristate computes(std::size_t pin1, std::size_t pin2, std::size_t pin3,
                std::size_t pin4, std::size_t out, std::size_t outb);
            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            nts::Tristate getNextValue() const override;
            std::string getPinType(std::size_t pin) override;
            void setPrev(nts::Tristate prev);
            nts::Tristate getPrevValue() const override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            std::string _name;
            size_t MAX_PIN;
            nts::Tristate _prev;
            nts::Clock _clock;
    };

}

#endif /* ! FLIPFLOP_HPP_ */
