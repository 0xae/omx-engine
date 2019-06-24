#ifndef VANILLAOPTION2_H
#define VANILLAOPTION2_H

#include "payoffbridge.h"

class VanillaOption {
public:
    VanillaOption(const PayoffBridge &payOff, double expiry);

    double CalcPayoff(double Spot) const;
    double GetExpiry() const;
    ~VanillaOption();

private:
    PayoffBridge ThePayoff;
    double Expiry;
};

#endif
