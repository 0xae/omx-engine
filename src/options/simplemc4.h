#ifndef SIMPLEMC4_H
#define SIMPLEMC4_H

#include "vanilla.h"

double SimpleMonteCarlo4(const VanillaOption& option,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths);

#endif