#include "antithetic.h"

AntiThetic::AntiThetic(const RandomBase &innerGenerator)
    : RandomBase(innerGenerator),
      InnerGenerator(innerGenerator.Clone())
{
    InnerGenerator->Reset();
    OddEven=true;
    NextVariates.resize(GetDimensionality());
}

unique_ptr<RandomBase> AntiThetic::Clone() const {
    return unique_ptr<RandomBase>(new AntiThetic(*InnerGenerator));
}

void AntiThetic::GetUniforms(MJArray &variates) {
    if (OddEven) {
        InnerGenerator->GetUniforms(variates);
        for (unsigned long i=0; i<GetDimensionality(); i++) {
            NextVariates[i]=1.0-variates[i];
        }
        OddEven=false;

    } else {
        variates=NextVariates;
        OddEven=true;
    }
}

void AntiThetic::Skip(unsigned long numberOfPaths) {
    if (numberOfPaths==0) {
        return;
    }

    if (OddEven) {
        OddEven=false;
        numberOfPaths--;
    }

    InnerGenerator->Skip(numberOfPaths / 2);
    if (numberOfPaths%2) {
        MJArray tmp(GetDimensionality());
        // triggers the generation
        GetUniforms(tmp);
    }
}

void AntiThetic::SetSeed(unsigned long Seed) {
    InnerGenerator->SetSeed(Seed);
    OddEven=true;
}

void AntiThetic::Reset() {
    InnerGenerator->Reset();
    OddEven=true;
}

void AntiThetic::ResetDimensionality(unsigned long NewDimensionality) {
    RandomBase::ResetDimensionality(NewDimensionality);
    NextVariates.resize(NewDimensionality);
    InnerGenerator->ResetDimensionality(NewDimensionality);
}