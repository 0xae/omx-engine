#include <cmath>
#include "exoticengine.h"

ExoticEngine::ExoticEngine(const PathDependent &TheProduct_, const Parameters& r_)
  : TheProduct(TheProduct_.Clone()), 
    r(r_),
    Discounts(TheProduct_.PossibleCashFlowTimes())
{
    for (unsigned long i=0; i < Discounts.size(); i++)
        Discounts[i] = exp(-r.Integral(0.0, Discounts[i]));
    
    TheCashFlows.resize(TheProduct->MaxNumberOfCashFlows());
}

void ExoticEngine::DoSimulation(StatisticsMC& TheGatherer, 
    unsigned long NumberOfPaths)
{
    MJArray SpotValues(TheProduct->GetLookAtTimes().size());
    TheCashFlows.resize(TheProduct->MaxNumberOfCashFlows());

    double thisValue;
    for (unsigned long i =0; i < NumberOfPaths; i++) {
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        TheGatherer.DumpOneResult(thisValue);
    }

}

double ExoticEngine::DoOnePath(const MJArray &SpotValues) const
{
    unsigned long NumberFlows =
    TheProduct->CashFlows(SpotValues, TheCashFlows);
    double Value=0.0;

    for (unsigned i =0; i < NumberFlows; ++i) {
        Value += TheCashFlows[i].Amount * Discounts[TheCashFlows[i].TimeIndex];
    }
    
    return Value;
}

