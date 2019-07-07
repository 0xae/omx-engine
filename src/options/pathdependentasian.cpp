#include "pathdependentasian.h"

using std::vector;
using std::unique_ptr;

PathDependentAsian::PathDependentAsian(const MJArray &LookAtTimes_,
                                       double DeliveryTime_,
                                       const PayoffBridge &ThePayOff_)
    : PathDependent(LookAtTimes_),
    DeliveryTime(DeliveryTime_),
    ThePayoff(ThePayOff_),
    NumberOfTimes(LookAtTimes_.size())
{
}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const {
    return 1UL;
}

MJArray PathDependentAsian::PossibleCashFlowTimes() const {
    MJArray tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}

unsigned long PathDependentAsian::CashFlows(const MJArray &SpotValues,
                                            vector<CashFlow> &GeneratedFlows) const {

    double sum=SpotValues.sum();
    double mean=sum/NumberOfTimes;

    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount = ThePayoff.Calculate(mean);

    return 1UL;
}

unique_ptr<PathDependent> PathDependentAsian::Clone() const {
    return unique_ptr<PathDependent> (new PathDependentAsian(*this));
}
