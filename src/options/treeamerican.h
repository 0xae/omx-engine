#ifndef TREE_AMERICAN_H
#define TREE_AMERICAN_H

#include <memory>
#include "treeproduct.h"
#include "payoffbridge.h"

using std::unique_ptr;

class TreeAmerican : public TreeProduct
{
public:
    TreeAmerican(double FinalTime,
                 const PayoffBridge &ThePayOff_);
    virtual ~TreeAmerican() {}

    virtual unique_ptr<TreeProduct> Clone() const;

    virtual double FinalPayOff(double Spot) const;

    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscountedFutureValue) const;
private:
    PayoffBridge ThePayOff;
};

#endif
