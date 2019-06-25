#include "payoffbridge.h"
#include <iostream>

PayoffBridge::PayoffBridge(const PayOff &payoff) 
{
    ThePayoff = payoff.Clone();
}

PayoffBridge::PayoffBridge(const PayoffBridge& original)
{
    ThePayoff = original.ThePayoff->Clone();
}

PayoffBridge& PayoffBridge::operator=(const PayoffBridge &original) 
{
    if (this != &original) {
        delete ThePayoff.release();
        ThePayoff = original.ThePayoff->Clone();
    }

    return *this;
}

double PayoffBridge::Calculate(double Spot) const {
    return ThePayoff->Calculate(Spot);
}

PayoffBridge::~PayoffBridge() {
    std::cout << "~PayoffBridge()" 
            << std::endl;
}
