#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "PayOff2.h"

class VanillaOption {
public:
    VanillaOption(PayOff &payOff, double expiry);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption &original);

    double CalcPayoff(double Spot) const;
    double GetExpiry() const;
    ~VanillaOption();

private:
    unique_ptr<PayOff> ThePayoff;
    double Expiry;
};

#endif
