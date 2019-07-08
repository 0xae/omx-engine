#include "PayOffForward.h"


PayOffForward::PayOffForward(double Strike_) : Strike(Strike_)
{
}

double PayOffForward::Calculate(double Spot) const
{
    return Spot-Strike;
}

unique_ptr<PayOff> PayOffForward::Clone() const
{
    return unique_ptr<PayOff>(new PayOffForward(*this));
}
