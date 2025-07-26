/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include "../AComponent.hpp"
#include "Clock.hpp"

namespace nts {

    class Logger : public nts::AComponent {
        public:
            Logger(const std::string &value);
            ~Logger();

            Tristate compute(std::size_t pin = 1)  override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)  override;
            void simulate(std::size_t tick)  override;

            void setPinState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getPinState(std::size_t pin) override;
            size_t getMaxPin() const override;
            std::string getPinType(std::size_t pin) override;
            nts::Tristate getNextValue() const override;
            nts::Tristate getPrevValue() const override;
            void update();
        protected:
            std::ofstream _BinFile;
            std::map<std::size_t, nts::Pin> _pins;
        private:
            size_t MAX_PIN;
            std::string _name;
            nts::IComponent *_linkedClockComponent;
            nts::Tristate _prevValue;
            std::string _valu;
            bool _asWritten;
    };
}
#endif /* !LOGGER_HPP_ */
