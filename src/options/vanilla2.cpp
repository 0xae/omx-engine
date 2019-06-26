#include "vanilla2.h"
#include <iostream>

VanillaOption::VanillaOption(const PayoffBridge &payoff, double expiry) 
  : ThePayoff(payoff), Expiry(expiry)
{
}

double VanillaOption::CalcPayoff(double Spot) const {
    return ThePayoff.Calculate(Spot);
}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

VanillaOption::~VanillaOption() {
    // std::cout << "VanillaOption::destructor()" << std::endl;
}
