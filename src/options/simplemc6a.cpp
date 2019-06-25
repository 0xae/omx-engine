#include <cmath>
#include <iostream>

#include "options/Random1.h"
#include "options/simplemc6a.h"

double SimpleMonteCarlo6a(const VanillaOption& option,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths)
{
    NumberOfPaths = fmax(NumberOfPaths, 1);

    double Expiry=option.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = Spot*exp(r.Integral(0,Expiry) + itoCorrection);
    double thisSpot;
    double runningSum=0;

    for (unsigned long i=0; i<NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);

        double thisPayOff = option.CalcPayoff(thisSpot);

        // std::cout << "gaussian: " << thisGaussian
        //     << ", thisSpot: " << thisSpot
        //     << ", movedSpot: " << movedSpot
        //     << ", payoff: " << thisPayOff
        //     << std::endl;
        runningSum += thisPayOff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r.Integral(0, Expiry));

    // std::cout << "mean: " << mean << std::endl;
    return mean;
}
