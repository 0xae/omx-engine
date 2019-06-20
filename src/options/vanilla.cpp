#include "vanilla.h"

VanillaOption::VanillaOption(PayOff &payoff, double expiry) 
    : ThePayoff(payoff), Expiry(expiry)
{
}

double VanillaOption::CalcPayoff(double Spot) const {
    return ThePayoff.Calculate(Spot);
}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

