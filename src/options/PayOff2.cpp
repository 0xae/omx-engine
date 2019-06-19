#include "PayOff2.h"
#include <math.h>

// PayOffCall
PayOffCall::PayOffCall(double Strike_): Strike(Strike_) {
}

double PayOffCall::Calculate (double Spot) const {
    return fmax(Spot-Strike, 0.0);
}

// PayOffPut
PayOffPut::PayOffPut(double Strike_): Strike(Strike_) {
}

double PayOffPut::Calculate (double Spot) const {
    return fmax(Strike-Spot, 0.0);
}
