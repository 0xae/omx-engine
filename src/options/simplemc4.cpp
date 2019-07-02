#include <cmath>
#include <iostream>
#include "options/simplemc4.h"
#include "options/Random1.h"

double SimpleMonteCarlo4(const VanillaOption& option,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths)
{
    double Expiry=option.GetExpiry();
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum=0;

    for (unsigned long i=0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);

        double thisPayOff = option.CalcPayoff(thisSpot);

        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}
