#include "doubledigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double lowerLevel, 
    double upperLevel) : LowerLevel(lowerLevel),
                        UpperLevel(upperLevel)
{
}

double PayOffDoubleDigital::Calculate(double Spot) const {
    if (Spot <= LowerLevel) {
        return 0;
    }

    if (Spot >= UpperLevel) {
        return 0;
    }

    return 1;
}
