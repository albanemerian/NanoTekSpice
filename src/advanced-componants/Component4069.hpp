/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
    #define COMPONENT4069_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"
#include "../componant/Not.hpp"

namespace nts {
class Component4069 : public nts::AComponent {
        public:
            Component4069(std::string const &value, ComponentFactory &factory);
            ~Component4069();

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
            nts::Not not1;
            nts::Not not2;
            nts::Not not3;
            nts::Not not4;
            nts::Not not5;
            nts::Not not6;
};
}
#endif /* !COMPONENT4069_HPP_ */
