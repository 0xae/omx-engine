#include "parkmiller.h"

using std::unique_ptr;

const long a=16907;
const long m=2147483647;
const long q=127773;
const long r=2836;

ParkMiller::ParkMiller(long Seed_) : Seed(Seed_) {
    if (Seed==0) {
        Seed=1;
    }
}

void ParkMiller::SetSeed(long Seed_) {
    Seed=Seed_;
    if (Seed==0) {
        Seed=1;
    }
}

unsigned long ParkMiller::Max() {
    return m-1;
}

unsigned long ParkMiller::Min() {
    return 1;
}

long ParkMiller::GetOneRandomInteger() {
    long k=Seed/q;
    Seed=a*(Seed-k*q)-r*k;
    if (Seed < 0) {
        Seed += m;
    }
    return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality,
                                   unsigned long Seed) 
    : RandomBase(Dimensionality), 
      InnerGenerator(Seed),
      InitialSeed(Seed) 
{
    Reciprocal = 1/(1.0+InnerGenerator.Max());
}

unique_ptr<RandomBase> RandomParkMiller::Clone() const {
    return unique_ptr<RandomBase>(new RandomParkMiller(*this));
}

void RandomParkMiller::GetUniforms(MJArray &variates) {
    for (unsigned long i = 0; i<GetDimensionality(); i++) {
        variates[i]=InnerGenerator.GetOneRandomInteger()*Reciprocal;
    }
}

void RandomParkMiller::Skip(unsigned long numberOfPaths) {
    MJArray tmp(GetDimensionality());
    for (unsigned long i = 0; i<numberOfPaths; i++) {
        GetUniforms(tmp);
    }
}

void RandomParkMiller::SetSeed(unsigned long Seed) {
    InitialSeed=Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset() {
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality) {
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}





