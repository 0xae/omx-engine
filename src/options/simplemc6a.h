#ifndef SIMPLEMC6A_H
#define SIMPLEMC6A_H

#include "vanilla2.h"
#include "parameters.h"

double SimpleMonteCarlo6a(const VanillaOption& option,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths
);

#endif
