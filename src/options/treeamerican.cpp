#include "treeamerican.h"
#include <math.h>

TreeAmerican::TreeAmerican(double FinalTime,
                            const PayoffBridge &ThePayOff_) :
                            TreeProduct(FinalTime),
                            ThePayOff(ThePayOff_) 
{
}

unique_ptr<TreeProduct> TreeAmerican::Clone() const {
    return unique_ptr<TreeProduct>(new TreeAmerican(*this));
}

double TreeAmerican::FinalPayOff(double Spot) const {
    return ThePayOff.Calculate(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double Time, 
                double DiscountedFutureValue) const  
{
    return fmax(ThePayOff.Calculate(Spot), DiscountedFutureValue);
}
