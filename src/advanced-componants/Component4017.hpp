/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Component4017
*/

#ifndef COMPONENT4017_HPP_
#define COMPONENT4017_HPP_

#include "../AComponent.hpp"
#include "../ComponentFactory.hpp"

namespace nts {

class Component4017 : public nts::AComponent{
    public:
        Component4017(std::string const &value, ComponentFactory &factory);
        ~Component4017();
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
        nts::Tristate _previousClock1;
        nts::Tristate _previousClock2;
        nts::Not _notCP1;
        nts::Or _orComp;

        nts::Tristate _prevFlip1;
        nts::Tristate _prevFlip2;
        nts::Tristate _prevFlip3;
        nts::Tristate _prevFlip4;
        nts::Tristate _prevFlip5;

        nts::FlipFlop _flipFlop1;
        nts::FlipFlop _flipFlop2;
        nts::FlipFlop _flipFlop3;
        nts::FlipFlop _flipFlop4;
        nts::FlipFlop _flipFlop5;

        nts::And _andClock;
        nts::And _andOr;

        nts::Nor _norOutput0;
        nts::Nor _norOutput1;
        nts::Nor _norOutput2;
        nts::Nor _norOutput3;
        nts::Nor _norOutput4;
        nts::Nor _norOutput5;
        nts::Nor _norOutput6;
        nts::Nor _norOutput7;
        nts::Nor _norOutput8;
        nts::Nor _norOutput9;

        int counter;
};
}

#endif /* !COMPONENT4017_HPP_ */
