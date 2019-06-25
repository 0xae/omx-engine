#include "payoffbridge.h"
#include <iostream>

PayoffBridge::PayoffBridge(const PayOff &payoff) 
{
    std::cout << "PayoffBridge(payoff)" 
        << std::endl;

    ThePayoff = payoff.Clone();
}

PayoffBridge::PayoffBridge(const PayoffBridge& original)
{
    std::cout << "PayoffBridge(&obj)" 
        << std::endl;

    ThePayoff = original.ThePayoff->Clone();
}

PayoffBridge& PayoffBridge::operator=(const PayoffBridge &original) 
{
    std::cout << "PayoffBridge=" 
        << std::endl;

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
