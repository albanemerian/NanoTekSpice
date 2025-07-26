/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** LoopFunction
*/

#ifndef LOOPFUNCTION_HPP_
#define LOOPFUNCTION_HPP_

#include <string>
#include "../ComponentFactory.hpp"

namespace nts {

    class LoopFunction {
        public:
            LoopFunction() = default;
            ~LoopFunction() = default;

            void loop_function(ComponentFactory &factory);
        private:
            void handleInput(const std::string &input, ComponentFactory &factory);
            void loop_input(ComponentFactory &factory);
    };

}
#endif /* !LOOPFUNCTION_HPP_ */
