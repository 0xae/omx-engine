#ifndef PAY_OFF_FORWARD_H
#define PAY_OFF_FORWARD_H

#include "PayOff2.h"
#include <memory>

using std::unique_ptr;

class PayOffForward : public PayOff {

public:
    PayOffForward(double Strike_);
    virtual ~PayOffForward(){}

    virtual double Calculate(double Spot) const;
    virtual unique_ptr<PayOff> Clone() const;

private:
    double Strike;
};

#endif
