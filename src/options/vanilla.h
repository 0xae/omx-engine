#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "PayOff2.h"

class VanillaOption {
public:
    VanillaOption(PayOff &payOff, double expiry);
    VanillaOption(const VanillaOption& original);
    VanillaOption& operator=(const VanillaOption & original);

    virtual double CalcPayoff(double Spot) const;
    double GetExpiry() const;
    virtual ~VanillaOption();
    unique_ptr<PayOff> ThePayoff;

private:
    double Expiry;
};

#endif
