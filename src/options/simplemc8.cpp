#include <cmath>
#include <iostream>

#include "options/simplemc8.h"

void SimpleMonteCarlo8(const VanillaOption& option,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths,
    StatisticsMC &gatherer,
    RandomBase &generator)
{
    NumberOfPaths = fmax(NumberOfPaths, 1);

    double Expiry=option.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot*exp(r.Integral(0,Expiry) + itoCorrection);
    double discounting=exp(-r.Integral(0, Expiry));
    double thisSpot;

    MJArray Variates(1);

    for (unsigned long i=0; i<NumberOfPaths; i++) {
        generator.GetGaussians(Variates);
        thisSpot = movedSpot*exp(rootVariance*Variates[0]);
        double thisPayOff = option.CalcPayoff(thisSpot);
        gatherer.DumpOneResult(thisPayOff * discounting);
    }
}
