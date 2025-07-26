/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4040
*/

#ifndef COMPONENT4040_HPP_
#define COMPONENT4040_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"

namespace nts {

class Component4040 : public nts::AComponent{
    public:
        Component4040(std::string const &value, ComponentFactory &factory);
        ~Component4040();
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
        nts::IComponent *_linkedClockComponent;
        std::string _name;
        ComponentFactory &_factory;
        nts::Tristate _previousClock;
        int counter;
};
}

#endif /* !COMPONENT4040_HPP_ */
