#ifndef ANTITETHIC_H
#define ANTITETHIC_H

#include "random2.h"
#include "arrays.h"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const RandomBase &base);
    ~AntiThetic() {}

    virtual unique_ptr<RandomBase> Clone() const;
    virtual void GetUniforms(MJArray &variates);
    virtual void Skip(unsigned long numberOfPaths);

    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
    unique_ptr<RandomBase> InnerGenerator;
    bool OddEven;
    MJArray NextVariates;
};

#endif
