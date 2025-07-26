/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4013
*/

#ifndef COMPONENT4013_HPP_
#define COMPONENT4013_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"

namespace nts {

class Component4013 : public nts::AComponent{
    public:
        Component4013(std::string const &value, ComponentFactory &factory);
        ~Component4013();
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
        nts::IComponent *_linkedClockComponent;
        nts::IComponent *_linkedClockComponent2;
        nts::Tristate _nextValue;
        nts::Tristate _nextValue2;
        size_t MAX_PIN;
        std::string _name;
        ComponentFactory &_factory;
        FlipFlop _flipFlop1;
        FlipFlop _flipFlop2;
};
}

#endif /* !COMPONENT4013_HPP_ */
