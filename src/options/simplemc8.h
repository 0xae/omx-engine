#ifndef SIMPLEMC8_H
#define SIMPLEMC8_H

#include "vanilla2.h"
#include "parameters.h"
#include "mcstatistics.h"
#include "antithetic.h"
#include "convergencetable.h"
#include "parkmiller.h"

void SimpleMonteCarlo8(const VanillaOption& option,
    double Spot,
    const Parameters& Vol,
    const Parameters& r,
    unsigned long NumberOfPaths,
    StatisticsMC &gatherer,
    RandomBase &generator
);

#endif
