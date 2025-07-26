/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
    #define COMPONENT4081_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"
#include "../componant/And.hpp"


namespace nts {

class Component4081 : public nts::AComponent {
        public:
            Component4081(std::string const &value,
                ComponentFactory &factory);
            ~Component4081();

            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;

            Tristate compute(std::size_t pin = 1)  override;
            void setPinState(std::size_t pin, nts::Tristate state) override;
            std::string getPinType(std::size_t pin);
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            std::string _name;
            ComponentFactory &_factory;
            nts::And and1;
            nts::And and2;
            nts::And and3;
            nts::And and4;
};
}
#endif /* !COMPONENT4081_HPP_ */
