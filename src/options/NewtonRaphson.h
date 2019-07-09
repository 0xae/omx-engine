#ifndef NEWTON_RAPH_H
#define NEWTON_RAPH_H

#include <cmath>

template <class T, double (T::*Value)(double) const,
                   double (T::*Derivative)(double) const>
double NewtonRaphson(double Target,
                     double Start,
                     double Tolerance,
                     const T &TheObj)
{
    double y=(TheObj.*Value)(Start);
    double x=Start;

    while (fabs(y-Target) > Tolerance) {
        double d=(TheObj.*Derivative)(x);

        x += (Target-y)/d;

        y = (TheObj.*Value)(x);
    }

    return x;
}

#endif
