/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
    #define COMPONENT4030_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"
#include "../componant/Xor.hpp"

namespace nts {
class Component4030 : public nts::AComponent {
        public:
            Component4030(std::string const &value,
                ComponentFactory &factory);
            ~Component4030();

            void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            std::string getPinType(std::size_t pin) override;
            Tristate compute(std::size_t pin = 1)  override;
            void setPinState(std::size_t pin, nts::Tristate state) override;

            protected:

            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            std::string _name;
            ComponentFactory &_factory;
            nts::Xor xor1;
            nts::Xor xor2;
            nts::Xor xor3;
            nts::Xor xor4;
};
}
#endif /* !COMPONENT4030_HPP_ */
