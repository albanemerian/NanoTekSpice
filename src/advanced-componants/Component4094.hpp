/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4094
*/

#ifndef COMPONENT4094_HPP_
#define COMPONENT4094_HPP_

#include <iostream>

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"
#include "../componant/Clock.hpp"

namespace nts {
    class Component4094 : public AComponent {
        public:
            Component4094(std::string const &value,
                ComponentFactory &factory);
            ~Component4094();
            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin) override;
            void setPinState(std::size_t pin, nts::Tristate state) override;
            size_t getMaxPin() const override;
            nts::Tristate getPinState(std::size_t pin) override;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin)  override;
            std::string getPinType(std::size_t pin) override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            std::string _name;
            ComponentFactory &_factory;
            nts::Clock _clock;
            nts::Tristate _lastClockState;
    };
}
#endif /* !COMPONENT4094_HPP_ */
