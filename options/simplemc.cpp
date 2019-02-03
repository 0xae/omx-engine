#include <stdio.h>
#include "Random1.h"
#include <iostream>
#include <cmath>

using namespace std;

double simpleMonteCarlo(double expiry, double strike,
        double spot, double vol, double r, int npaths) {
    double variance = vol*vol*expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = spot*exp(r*expiry+itoCorrection);
    double thisSpot;
    double sum=0;

    for (int i=0; i<npaths; ++i) {
        double gaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*gaussian);
        double payoff = thisSpot-strike;
        payoff = (payoff>0)?payoff : 0;
        sum += payoff;
    }

    double mean = sum / npaths;
    mean *= exp(-r*expiry);

    printf(
        "variance: %f\nrootVariance: %f\nitoCorrection: %f\nmovedSpot: %f\n",
        variance, rootVariance, itoCorrection, movedSpot
    );

    printf(
        "sum: %f\nmean: %f\n",
        sum, mean
    );

    return mean;
}

int main(int argc, char const *argv[]) {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    int NPaths;

    cout << "expiry: ";
    cin >> Expiry;

    cout << "strike: ";
    cin >> Strike;

    cout << "spot: ";
    cin >> Spot;

    cout << "vol: ";
    cin >> Vol;

    cout << "r: ";
    cin >> r;

    cout << "Number of paths: ";
    cin >> NPaths;

    double result = simpleMonteCarlo(Expiry, Strike, Spot, Vol, r, NPaths);

    cout << "The price is " << result << "$00\n";
    return 0;
}
