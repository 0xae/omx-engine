#ifndef RANDOM2_H
#define RANDOM2_H

#include <memory>

using std::unique_ptr;

class RandomBase
{
public:
    RandomBase(unsigned long Dimensionality);
    ~RandomBase() {}

    unsigned long GetDimensionality() const;
    virtual unique_ptr<RandomBase> Clone() const=0;
    virtual void GetUniforms(MJArray &variates)=0;
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SedSeed(unsigned long Seed)=0;
    virtual void Reset()=0;
    virtual void GetGaussians(MJArray &variates);
    virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
    unsigned long Dimensionality;
};

#endif
