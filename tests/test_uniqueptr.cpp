#include <stdio.h>
#include <iostream>
#include <memory>
#include <cmath>
// #include "options/Random1.h"
#include "options/vanilla.h"

using std::unique_ptr;

void printPayoff(std::string context, double value) {
    std::cout << "payoff of "
            << context
            << " is: "
            << "$"
            << value
            << ".00"
            << std::endl;    
}

int main(int argc, char const *argv[]) {
    double spot=15;
    double strike=25;

    PayOffPut payoffPut(strike);
    PayOffPut payoffPut2(strike*0.5);

    printPayoff("put", payoffPut.Calculate(spot));

    unique_ptr<VanillaOption> option_ptr(new VanillaOption(payoffPut, strike));
    printPayoff("option[put]", option_ptr->CalcPayoff(spot));

    unique_ptr<PayOff> ptr=payoffPut.Clone();
    printPayoff("put2", ptr->Calculate(spot));

    return 0;
}
