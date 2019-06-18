#include <stdio.h>
#include <iostream>
#include <cmath>

#include "Random1.h"
#include "payoff1.h"

int main(int argc, char const *argv[]) {
    double spot;
    double strike;
    PayOff.OptionType t=call;
    std::string otype;

    std::cout << "Option Type (sell, call)";
    std::cin >> otype;

    std::cout << "strike: ";
    std::cin >> strike;

    std::cout << "spot: ";
    cin >> spot;

    return 0;
}
