#include <cmath>
#include <iostream>

#include "options/simplemc7.h"

void SimpleMonteCarlo7(const VanillaOption& option,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths,
    StatisticsMC &gatherer)
{
    NumberOfPaths = fmax(NumberOfPaths, 1);

    double Expiry=option.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot*exp(r.Integral(0,Expiry) + itoCorrection);
    double discounting=exp(-r.Integral(0, Expiry));
    double thisSpot;

    for (unsigned long i=0; i<NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);
        double thisPayOff = option.CalcPayoff(thisSpot);
        gatherer.DumpOneResult(thisPayOff*discounting);
    }
}
