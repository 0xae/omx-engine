#include "treeeuropean.h"

TreeEuropean::TreeEuropean(double FinalTime,
                            const PayoffBridge &ThePayOff_) :
                            TreeProduct(FinalTime),
                            ThePayOff(ThePayOff_) 
{
}

unique_ptr<TreeProduct> TreeEuropean::Clone() const {
    return unique_ptr<TreeProduct>(new TreeEuropean(*this));
}

double TreeEuropean::FinalPayOff(double Spot) const {
    return ThePayOff.Calculate(Spot);
}

double TreeEuropean::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const  {
    return DiscountedFutureValue;
}
