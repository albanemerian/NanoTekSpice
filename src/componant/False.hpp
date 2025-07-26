/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** False
*/

#ifndef FALSE_HPP_
    #define FALSE_HPP_

#include "../AComponent.hpp"

namespace nts {

    class False : public nts::AComponent {
        public:
            False(std::string const &value);
            ~False();

            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            nts::Tristate getNextValue() const override;
            nts::Tristate getPrevValue() const override;
            std::string getPinType(std::size_t pin) override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
    };

}

#endif /* ! FALSE_HPP_ */
