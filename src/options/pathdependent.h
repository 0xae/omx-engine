#ifndef PATH_DEPENDENT_H
#define PATH_DEPENDENT_H

#include <vector>
#include <memory>
#include "arrays.h"

using std::vector;
using std::unique_ptr;

class CashFlow {
public:
    double Amount;
    unsigned long TimeIndex;
    CashFlow(unsigned long TimeIndex_=0UL, double Amount_=0.0)
        : Amount(Amount_), TimeIndex(TimeIndex_)
    {
    }
};

class PathDependent {
public:
    PathDependent(const MJArray &LookAtTimes);
    virtual ~PathDependent() {}

    const MJArray& GetLookAtTimes() const;
    virtual unsigned long MaxNumberOfCashFlows() const=0;
    virtual MJArray PossibleCashFlowTimes() const=0;
    virtual unsigned long CashFlows(
        const MJArray &SpotValues,
        vector<CashFlow> &GeneratedFlows
    ) const=0;

    virtual unique_ptr<PathDependent> Clone() const=0;

private:
    MJArray LookAtTimes;
};

#endif
