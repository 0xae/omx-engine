#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H

#include "options/PayOff2.h"

double SimpleMonteCarlo3(const PayOff& thePayOff,
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths);

#endif