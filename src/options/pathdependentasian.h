#ifndef PATH_DEPENDENT_ASIAN
#define PATH_DEPENDENT_ASIAN

#include <vector>
#include <memory>
#include "pathdependent.h"
#include "payoffbridge.h"

using std::vector;
using std::unique_ptr;

class PathDependentAsian : public PathDependent
{
public:
    PathDependentAsian(const MJArray &LookAtTimes,
                        double DeliveryTime_,
                        const PayoffBridge &ThePayOff_);
    virtual ~PathDependentAsian() {}

    virtual unsigned long MaxNumberOfCashFlows() const;
    virtual MJArray PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const MJArray& SpotValues,
                                    vector<CashFlow> &GeneratedFlows) const;

    virtual unique_ptr<PathDependent> Clone() const;

private:
    double DeliveryTime;
    PayoffBridge ThePayoff;
    unsigned long NumberOfTimes;
};

#endif
