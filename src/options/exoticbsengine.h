#ifndef EXOTIC_BS_ENGINE
#define EXOTIC_BS_ENGINE

#include "exoticengine.h"
#include "random2.h"

class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const PathDependent &TheProduct_,
                   const Parameters &R_,
                   const Parameters &D_,
                   const Parameters &Vol_,
                   const RandomBase &TheGenerator_,
                   double Spot_);

    virtual void GetOnePath(MJArray &SpotValues);

    virtual ~ExoticBSEngine() {}

private:
    unique_ptr<RandomBase> TheGenerator;
    MJArray Drifts;
    MJArray StandardDevs;
    double LogSpot;
    unsigned long NumberOfTimes;
    MJArray Variates;
};

#endif
