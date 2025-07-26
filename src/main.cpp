/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** main
*/

#include <iostream>
#include <string.h>
#include "error/ErrorParser.hpp"
#include "functions/LoopFunction.hpp"
#include "parsing/ParseFile.hpp"


void helper() {

    std::cout << "USAGE\n"
    << "\t./nanotechspice file.nts\n\n"
    << "DESCRIPTION\n"
    << "\tfile.nts\tfile describing the circuit.\n";
    std::cout << "USAGE IN LOOP\n" << std::endl;
    std::cout << "\tdisplay or D\n"<<
    "\tsimulate or S\n" <<
    "\texit\n" <<
    "\tloop\n" <<
    "\tclear\n "<<
    "\t[name]=[value]  (only for input or clock componants)\n" << std::endl;

}

int main(int argc, char **argv) {

    nts::ErrorParser pars;
    nts::LoopFunction loopfunc;
    nts::ParseFile file;

    if (argc != 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        helper();
        exit(84);
    }
    try {
        pars.parseFunction(argv[1]);
        nts::ComponentFactory &factory = file.parseFunction(pars);
        loopfunc.loop_function(factory);
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}
