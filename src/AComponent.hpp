/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <vector>
#include "IComponent.hpp"
#include "componant/Pin.hpp"

namespace nts {

    class AComponent : public nts::IComponent {
        public:
            AComponent();
            ~AComponent();

            void simulate(std::size_t tick)  override;
            Tristate compute(std::size_t pin = 1)  override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)  override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            std::string getPinType(std::size_t pin) override;
            nts::Tristate getNextValue() const override;
            nts::Tristate getPrevValue() const override;
        protected:
            std::map<std::size_t, nts::Pin> _pins;
        private:
    };

}
#endif /* !ACOMPONENT_HPP_ */
