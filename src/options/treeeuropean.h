#ifndef TREE_EUROPEAN_H
#define TREE_EUROPEAN_H

#include <memory>
#include "treeproduct.h"

using std::unique_ptr;

class TreeEuropean : public TreeProduct
{
public:
    TreeEuropean(double FinalTime,
                 const PayoffBridge &ThePayOff_);
    virtual ~TreeEuropean() {}

    virtual unique_ptr<TreeProduct> Clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscountedFutureValue) const;
private:
    PayoffBridge ThePayOff;
};

#endif
