#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "PayOff2.h"

class VanillaOption {
public:
    VanillaOption(PayOff &payOff, double expiry);
    virtual double CalcPayoff(double Spot) const;
    double GetExpiry() const;
    virtual ~VanillaOption() {};

private:
    PayOff &ThePayoff;
    double Expiry;
};

#endif
