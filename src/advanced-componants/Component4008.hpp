/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4008
*/

#ifndef COMPONENT4008_HPP_
    #define COMPONENT4008_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"

namespace nts {
    class Component4008 : public nts::AComponent {
        public:
            Component4008(std::string const &value,
                ComponentFactory &factory);
            ~Component4008();
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
            Sum _sum1;
            Sum _sum2;
            Sum _sum3;
            Sum _sum4;
    };
}
#endif /* !COMPONENT4008_HPP_ */
