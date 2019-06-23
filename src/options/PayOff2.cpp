#include "PayOff2.h"
#include <math.h>
#include <iostream>

// Option Call
PayOffCall::PayOffCall(double Strike_): Strike(Strike_) {
}

double PayOffCall::Calculate (double Spot) const {
    // std::cout << "option[call]: spot("<<Spot
    //     << ") - strike(" << Strike << ")"
    //     << std::endl;

    return fmax(Spot-Strike, 0.0);
}

unique_ptr<PayOff> PayOffCall::Clone() const {
    return unique_ptr<PayOff>(new PayOffCall(*this));
}

// Option Put
PayOffPut::PayOffPut(double Strike_): Strike(Strike_) {
}

double PayOffPut::Calculate (double Spot) const {
    // std::cout << "option[put]: strike("<<Strike
    //     << ") - spot(" << Spot << ")"
    //     << std::endl;

    return fmax(Strike-Spot, 0.0);
}

unique_ptr<PayOff> PayOffPut::Clone() const {
    return unique_ptr<PayOff>(new PayOffPut(*this));
}
