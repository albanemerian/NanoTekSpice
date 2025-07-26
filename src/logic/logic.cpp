/*
** EPITECH PROJECT, 2025
** B-OOP-400-NAN-4-1-tekspice-matisse.marsac
** File description:
** logic
*/

#include <iostream>
#include "logic.hpp"

std::map<std::size_t, nts::Pin> nts::_pins;

nts::Tristate nts::And_logic(nts::Tristate p1, nts::Tristate p2, size_t out) {
    if (p1 == nts::Tristate::True && p2 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    // if (p1 == nts::Tristate::False && p2 == nts::Tristate::False) { // remove this
    //     _pins[out]._value = nts::Tristate::True;
    //     return nts::Tristate::True;
    // }
    if (p1 == nts::Tristate::False || p2 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Or_logic(nts::Tristate p1, nts::Tristate p2, size_t out) {
    if (p1 == nts::Tristate::True || p2 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    if (p1 == nts::Tristate::False && p2 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Clock_logic(nts::Tristate p1, size_t out) {
    if (p1 == nts::Tristate::Undefined) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    if (p1 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    if (p1 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Xor_logic(nts::Tristate p1, nts::Tristate p2, size_t out) {
    if (p1 == nts::Tristate::Undefined || p2 == nts::Tristate::Undefined) {
        _pins[out]._value = nts::Tristate::Undefined;
        return nts::Tristate::Undefined;
    }
    if (p1 == nts::Tristate::True && p2 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    if (p1 == nts::Tristate::True || p2 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    if (p1 == nts::Tristate::False && p2 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::Nand_logic(nts::Tristate p1, nts::Tristate p2, size_t out) {
    if (p1 == nts::Tristate::False || p2 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    if (p1 == nts::Tristate::True && p2 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}
// nts::Tristate nts::Nand_logic(nts::Tristate p1, nts::Tristate p2, size_t out) {
//     if (p1 == nts::Tristate::Undefined || p2 == nts::Tristate::Undefined) {
//         _pins[out]._value = nts::Tristate::Undefined;
//         return nts::Tristate::Undefined;
//     }
//     if (p1 == nts::Tristate::False || p2 == nts::Tristate::False) {
//         _pins[out]._value = nts::Tristate::True;
//         return nts::Tristate::True;
//     }
//     _pins[out]._value = nts::Tristate::False;
//     return nts::Tristate::False;
// }

nts::Tristate nts::Nor_logic(nts::Tristate p1, nts::Tristate p2, size_t out) {
    if (p1 == nts::Tristate::False && p2 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    if (p1 == nts::Tristate::True || p2 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}


nts::Tristate nts::Not_logic(nts::Tristate p1, size_t out) {
    if (p1 == nts::Tristate::True) {
        _pins[out]._value = nts::Tristate::False;
        return nts::Tristate::False;
    }
    if (p1 == nts::Tristate::False) {
        _pins[out]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    _pins[out]._value = nts::Tristate::Undefined;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::True_logic(nts::Tristate p1, size_t out) {
    (void)p1;
    _pins[out]._value = nts::Tristate::True;
    return nts::Tristate::True;
}

nts::Tristate nts::False_logic(nts::Tristate p1, size_t out)
{
    (void)p1;
    _pins[out]._value = nts::Tristate::False;
    return nts::Tristate::False;
}

nts::Tristate nts::Sum_logic(nts::Tristate a, nts::Tristate b, nts::Tristate carryIn, size_t sum) {
    int sumValue = (int)a + (int)b + (int)carryIn;

    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || carryIn == nts::Tristate::Undefined) {
        _pins[sum]._value = nts::Tristate::Undefined;
        return nts::Tristate::Undefined;
    }
    if (sumValue == 1 || sumValue == 3) {
        _pins[sum]._value = nts::Tristate:: True;
        return nts::Tristate::True;
    }
    _pins[sum]._value = nts::Tristate::False;
    return nts::Tristate::False;
}

nts::Tristate nts::Carry_logic(nts::Tristate a, nts::Tristate b, nts::Tristate carryIn, size_t carryOut) {
    int sumValue = (int)a + (int)b + (int)carryIn;

    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || carryIn == nts::Tristate::Undefined) {
        _pins[carryOut]._value = nts::Tristate::Undefined;
        return nts::Tristate::Undefined;
    }
    if (sumValue == 2 || sumValue == 3) {
        _pins[carryOut]._value = nts::Tristate::True;
        return nts::Tristate::True;
    }
    _pins[carryOut]._value = nts::Tristate::False;
    return nts::Tristate::False;
}

nts::Tristate nts::Flipflop_logic(nts::Tristate clkState, nts::Tristate prevClkState,
    nts::Tristate dState, nts::Tristate setState, nts::Tristate resetState,
    nts::Tristate Qvalue, size_t q, size_t qNot) {

    if (setState == nts::Tristate::True && resetState == nts::Tristate::True) {
        _pins[q]._value = nts::Tristate::True;
        _pins[qNot]._value = nts::Tristate::True;
        return _pins[q]._value;
    }
    if (setState == nts::Tristate::True) {
        _pins[q]._value = nts::Tristate::True;
        _pins[qNot]._value = nts::Tristate::False;
        return _pins[q]._value;
    }
    if (resetState == nts::Tristate::True) {
        _pins[q]._value = nts::Tristate::False;
        _pins[qNot]._value = nts::Tristate::True;
        return _pins[q]._value;
    }
    if (prevClkState == nts::Tristate::False && clkState == nts::Tristate::True) {
        if (dState == nts::Tristate::Undefined) {
            _pins[q]._value = nts::Tristate::Undefined;
            _pins[qNot]._value = nts::Tristate::Undefined;
            return _pins[q]._value;
        } else {
            _pins[q]._value = dState;
            _pins[qNot]._value = (dState == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True;
            return _pins[q]._value;
        }
    }
    if (clkState == nts::Tristate::False && Qvalue != nts::Tristate::Undefined) {
        _pins[q]._value = _pins[q]._value;
        _pins[qNot]._value = _pins[qNot]._value;
        return _pins[q]._value;
    }
    if (prevClkState == nts::Tristate::True && clkState == nts::Tristate::True && Qvalue != nts::Tristate::Undefined) {
        _pins[q]._value = _pins[q]._value;
        _pins[qNot]._value = _pins[qNot]._value;
        return _pins[q]._value;
    }
    if (prevClkState == nts::Tristate::False && clkState == nts::Tristate::False && Qvalue != nts::Tristate::Undefined) {
        _pins[q]._value = _pins[q]._value;
        _pins[qNot]._value = _pins[qNot]._value;
        return _pins[q]._value;
    }
    return nts::Tristate::Undefined;
}



nts::Tristate nts::Counter_logic(nts::Tristate c, nts::Tristate r, size_t q, size_t qNot) {
    if (r == nts::Tristate::True) {
        _pins[q]._value = nts::Tristate::False;
        _pins[qNot]._value = nts::Tristate::False;
    } else if (c == nts::Tristate::True) {
        _pins[q]._value = nts::Tristate::True;
        _pins[qNot]._value = nts::Tristate::False;
    } else if (c == nts::Tristate::False) {
        _pins[q]._value = nts::Tristate::False;
        _pins[qNot]._value = nts::Tristate::True;
    }
    return _pins[q]._value;
}

int nts::Selector_logic(nts::Tristate a, nts::Tristate b, nts::Tristate c) {
    if (a == nts::Tristate::False && b == nts::Tristate::False && c == nts::Tristate::False)
        return 1;
    else if (a == nts::Tristate::True && b == nts::Tristate::False && c == nts::Tristate::False)
        return 2;

    else if (a == nts::Tristate::False && b == nts::Tristate::True && c == nts::Tristate::False)
        return 3;
    else if (a == nts::Tristate::True && b == nts::Tristate::True && c == nts::Tristate::False)
        return 4;
    else if (a == nts::Tristate::False && b == nts::Tristate::False && c == nts::Tristate::True)
        return 5;
    else if (a == nts::Tristate::True && b == nts::Tristate::False && c == nts::Tristate::True)
      return 6;
    else if (a == nts::Tristate::False && b == nts::Tristate::True && c == nts::Tristate::True)
        return 7;
    else if (a == nts::Tristate::True && b == nts::Tristate::True && c == nts::Tristate::True)
        return 9;
    return 0;
}
