#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H

#include "vanilla2.h"
#include "parameters.h"
#include "mcstatistics.h"
#include "Random1.h"

void SimpleMonteCarlo7(const VanillaOption& option,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths,
    StatisticsMC &gatherer
);

#endif
