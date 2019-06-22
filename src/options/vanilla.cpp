#include "vanilla.h"
#include <iostream>

VanillaOption::VanillaOption(PayOff &payoff, double expiry) 
{
    ThePayoff = payoff.Clone();
    Expiry = expiry;
}

VanillaOption::VanillaOption(const VanillaOption& original) 
{
    Expiry = original.Expiry;
    ThePayoff = original.ThePayoff->Clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption &original) 
{
    if (this != &original) {    
        Expiry = original.Expiry;
        delete ThePayoff.release();
        ThePayoff = original.ThePayoff->Clone();
    }

    return *this;
}

double VanillaOption::CalcPayoff(double Spot) const {
    return ThePayoff->Calculate(Spot);
}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

VanillaOption::~VanillaOption() {
    std::cout << "VanillaOption::destructor()" << std::endl;
}
