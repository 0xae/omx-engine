#ifndef RANDOM2_H
#define RANDOM2_H

#include <memory>
#include "arrays.h"
#include "normals.h"

using std::unique_ptr;

class RandomBase
{
public:
    RandomBase(unsigned long Dimensionality);
    ~RandomBase() {}

    virtual unique_ptr<RandomBase> Clone() const=0;
    virtual void GetUniforms(MJArray &variates)=0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SetSeed(unsigned long Seed)=0;
    virtual void Reset()=0;
    unsigned long GetDimensionality() const;
    virtual void GetGaussians(MJArray &variates);
    virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
    unsigned long Dimensionality;
};

#endif
