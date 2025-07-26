/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** parseFile
*/

#ifndef PARSEFILE_HPP_
#define PARSEFILE_HPP_

#include "../error/ErrorParser.hpp"
#include "../ComponentFactory.hpp"

namespace nts {

    class ParseFile {
        public:
            ParseFile() = default;
            ~ParseFile() = default;

            ComponentFactory& parseFunction(ErrorParser error);
        protected:
        private:
            ComponentFactory factory;
    };
}

#endif /* !PARSEFILE_HPP_ */

