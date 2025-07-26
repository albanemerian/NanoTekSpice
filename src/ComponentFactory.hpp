/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** ComponentFactory
*/

#ifndef ComponentFactory_HPP_
#define ComponentFactory_HPP_

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <map>
#include <unordered_map>
#include <queue>
#include "AComponent.hpp"
#include "error/ErrorParser.hpp"
#include "componant/And.hpp"
#include "componant/Or.hpp"
#include "componant/Xor.hpp"
#include "componant/Not.hpp"
#include "componant/Nor.hpp"
#include "componant/True.hpp"
#include "componant/False.hpp"
#include "componant/Sum.hpp"
#include "componant/Clock.hpp"
#include "componant/Logger.hpp"
#include "componant/FlipFlop.hpp"
#include "componant/Counter.hpp"
#include "componant/AndThree.hpp"

namespace nts {

    class ComponentFactory {
        public:

            ComponentFactory() = default;
            ~ComponentFactory() = default;

            ComponentFactory(const ComponentFactory&) = delete;
            ComponentFactory& operator=(const ComponentFactory&) = delete;

            ComponentFactory(ComponentFactory&&) = default;
            ComponentFactory& operator=(ComponentFactory&&) = default;

            std::unique_ptr<nts::AComponent> createComponent(const std::string &type, const std::string &value);
            std::unique_ptr<nts::AComponent> createInput(const std::string &value);
            std::unique_ptr<nts::AComponent> createOutput(const std::string &value);
            std::unique_ptr<nts::AComponent> createClock(const std::string &value);
            std::unique_ptr<nts::AComponent> createTrue(const std::string &value);
            std::unique_ptr<nts::AComponent> createFalse(const std::string &value);
            std::unique_ptr<nts::AComponent> createLogger(const std::string &value);


            void addComponent(const std::string &name, std::unique_ptr<AComponent> component);
            void createLink(const std::string &comp1, size_t pin1, const std::string &comp2, size_t pin2);

            void simulate();
            void setValue(const std::string &name, nts::Tristate value);
            void display();

        protected:

        private:
            std::unordered_map<std::string, std::unique_ptr<AComponent>> components;
            std::map<std::string, std::string> outputs;
            size_t tick{0};
            std::vector<std::pair<std::pair<std::string, size_t>, std::pair<std::string, size_t>>> links;
            void updateLinkedPinState(const std::string &name, size_t pin, nts::Tristate value);
            std::queue<std::pair<std::pair<std::string, size_t>, nts::Tristate>> pendingUpdates; // New member variable
            std::vector<std::string> componentOrder; // New member variable
    };
}

#include "advanced-componants/Component4001.hpp"
#include "advanced-componants/Component4008.hpp"
#include "advanced-componants/Component4011.hpp"
#include "advanced-componants/Component4030.hpp"
#include "advanced-componants/Component4069.hpp"
#include "advanced-componants/Component4071.hpp"
#include "advanced-componants/Component4081.hpp"
#include "advanced-componants/Component4801.hpp"
#include "advanced-componants/Component4013.hpp"
#include "advanced-componants/Component4017.hpp"
#include "advanced-componants/Component4512.hpp"
#include "advanced-componants/Component4514.hpp"
#include "advanced-componants/Component4094.hpp"
#include "advanced-componants/Component4040.hpp"

#endif /* !ComponentFactory_HPP_ */
