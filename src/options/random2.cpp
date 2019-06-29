#include "random2.h"
#include "normals.h"
#include <cstdlib>

unsigned long RandomBase::GetDimensionality() const {
    return Dimensionality;
}

void RandomBase::GetGaussians(MJArray &variates) {
    GetUniforms(variates);

    for (unsigned long i=0; i<Dimensionality; i++) {
        double x=variates[i];
        variates[i]=InverseCumulativeNormal(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality) {
    Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_) 
    : Dimensionality(Dimensionality_) {
}


