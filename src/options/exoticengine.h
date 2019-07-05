#ifndef EXOTIC_ENGINE_H
#define EXOTIC_ENGINE_H

#include <vector>
#include <memory>
#include "parameters.h"
#include "pathdependent.h"
#include "mcstatistics.h"

using std::vector;
using std::unique_ptr;

class ExoticEngine {
public:
    ExoticEngine(const PathDependent &TheProduct_, 
                 const Parameters &r);
    virtual ~ExoticEngine() {}

    void DoSimulation(StatisticsMC &TheGatherer,
                      unsigned long NumberOfPaths);

    double DoOnePath(const MJArray &SpotValues) const;

    virtual void GetOnePath(MJArray &SpotValues)=0;

private:
    unique_ptr<PathDependent> TheProduct;
    Parameters r;
    MJArray Discounts;
    mutable vector<CashFlow> TheCashFlows;
};

#endif
