#include <stdio.h>
#include <iostream>
#include <cmath>

#include "options/Random1.h"
#include "options/payoff1.h"

int main(int argc, char const *argv[]) {
    double spot;
    double strike;
    PayOff::OptionType t=PayOff::call;
    std::string otype;

    std::cout << "Option Type (put, call)";
    std::cin >> otype;

    if (otype=="put") {
        t=PayOff::put;
    } else if (otype!="call") {
        std::cout << "Invalid option type "+otype;
        return -1;
    }

    std::cout << "strike: ";
    std::cin >> strike;

    std::cout << "spot: ";
    cin >> spot;

    PayOff pay(strike, t);
    double payoff=pay.Calculate(spot);

    std::cout << "Pay off is " 
            << payoff
            << ".00$"
            << std::endl;

    return 0;
}
