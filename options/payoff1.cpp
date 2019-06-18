#include "payoff1.h"
#include <algorithm>
#include <math.h>

using std::max;

PayOff::PayOff(double strike, OptionType optionType) 
    : Strike(strike), 
    TheOptionType(optionType) 
{
}

double PayOff::Calculate(double spot) const {
    switch (TheOptionType) {
        case call:
            return fmax(spot-Strike,0.0);

        case put:
            return fmax(Strike-spot,0.0);

        default:
            return -1;
    }
}