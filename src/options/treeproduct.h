#ifndef TREE_PRODUCT_H
#define TREE_PRODUCT_H

#include <memory>

using std::unique_ptr;

class TreeProduct
{
public:
    TreeProduct(double FinalTime_);
    virtual ~TreeProduct() {}

    virtual double FinalPayOff(double Spot) const=0;

    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscountedFutureValue)=0;

    virtual unique_ptr<TreeProduct> Clone() const=0;
    double GetFinalTime() const;

private:
    double FinalTime;
};

#endif