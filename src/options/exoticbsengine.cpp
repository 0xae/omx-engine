#include <cmath>
#include "exoticbsengine.h"

ExoticBSEngine::ExoticBSEngine(const PathDependent& TheProduct_,
    const Parameters& R_,
    const Parameters& D_,
    const Parameters& Vol_,
    const RandomBase& TheGenerator_,
    double Spot_)
:   ExoticEngine(TheProduct_, R_),
    TheGenerator(TheGenerator_.Clone())
{
    MJArray Times(TheProduct_.GetLookAtTimes());
    NumberOfTimes = Times.size();
    TheGenerator->ResetDimensionality(NumberOfTimes);
    Drifts.resize(NumberOfTimes);
    StandardDevs.resize(NumberOfTimes);

    double Variance = Vol_.IntegralSquare(0,Times[0]);

    Drifts[0] = R_.Integral(0.0,Times[0])
        - D_.Integral(0.0,Times[0]) - 0.5 * Variance;

    StandardDevs[0] = sqrt(Variance);

    for (unsigned long j=1; j < NumberOfTimes; ++j)
    {
        double thisVariance = Vol_.IntegralSquare(Times[j-1],Times[j]);
        Drifts[j] = R_.Integral(Times[j-1],Times[j])
                    - D_.Integral(Times[j-1],Times[j])
                    - 0.5 * thisVariance;
        StandardDevs[j] = sqrt(thisVariance);
    }

    LogSpot = log(Spot_);
    Variates.resize(NumberOfTimes);
}


void ExoticBSEngine::GetOnePath(MJArray& SpotValues)
{
    TheGenerator->GetGaussians(Variates);
    double CurrentLogSpot = LogSpot;

    for (unsigned long j=0; j < NumberOfTimes; j++)
    {
        CurrentLogSpot += Drifts[j];
        CurrentLogSpot += StandardDevs[j]*Variates[j];
        SpotValues[j] = exp(CurrentLogSpot);
    }

    return;
}

