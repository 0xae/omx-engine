#include <cmath>
#include "options/simplemc3.h"
#include "options/Random1.h"

double SimpleMonteCarlo3(const PayOff& payOff,
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths)
{
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum=0;

    for (unsigned long i=0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp( rootVariance*thisGaussian);

        double thisPayOff = payOff.Calculate(thisSpot);
        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}
