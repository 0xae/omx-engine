#include "pathdependent.h"

PathDependent::PathDependent(const MJArray& LookAtTimes_) 
    : LookAtTimes(LookAtTimes_) 
{
}

const MJArray& PathDependent::GetLookAtTimes() const {
    return LookAtTimes;
}
