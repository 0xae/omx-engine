#ifndef SIMPLEMC5_H
#define SIMPLEMC5_H

#include "vanilla2.h"

double SimpleMonteCarlo5(const VanillaOption& option,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths);

#endif