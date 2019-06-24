#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "PayOff2.h"

class PayoffBridge {
public:
    PayoffBridge(const PayOff &payOff);
    PayoffBridge(const PayoffBridge &original);
    PayoffBridge& operator=(const PayoffBridge &original);

    double Calculate(double Spot) const;
    ~PayoffBridge();

private:
    unique_ptr<PayOff> ThePayoff;
};

#endif
