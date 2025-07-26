/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** IComponant
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <array>
#include <map>
#include <utility>

namespace nts
{
	enum class Tristate
	{
		Undefined = (-true),
        True = true,
        False = false
	};

	class IComponent
	{
	public:
		IComponent() = default;
		virtual ~IComponent() = default;

		IComponent(IComponent &&) = default;

		IComponent &operator=(IComponent &&) = default;

        virtual void simulate(std::size_t tick) = 0;
		virtual Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

		virtual void setPinState(std::size_t pin, nts::Tristate state) = 0;
		virtual nts::Tristate getPinState(std::size_t pin) = 0;
		virtual size_t getMaxPin() const = 0;
		virtual std::string getPinType(std::size_t pin) = 0;
		virtual nts::Tristate getNextValue() const = 0;
		virtual nts::Tristate getPrevValue() const = 0;

	};
}

std::ostream &operator<<(std::ostream &os, nts::Tristate state);

#endif /* !ICOMPONENT_HPP_ */
