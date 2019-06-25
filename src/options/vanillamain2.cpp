#include <iostream>
#include "options/PayOff2.h"
#include "options/vanilla2.h"
#include "options/simplemc5.h"

using std::cout;
using std::cin;
using std::endl;

void fromPayoffBridge(PayoffBridge &bridge, double Spot) {
    std::cout << "option payoff: "
        << bridge.Calculate(Spot)
        << std::endl;
}

int main(int argc, char const *argv[])
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
 
    cout << "\nEnter expiry\n";
    cin >> Expiry;
 
    cout << "\nEnter strike\n";
    cin >> Strike;
 
    cout << "\nEnter spot\n";
    cin >> Spot;
 
    cout << "\nEnter vol\n";
    cin >> Vol;
 
    cout << "\nr\n";
    cin >> r;

    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffPut payOff(Strike);
    // PayoffBridge bridge(payOff);
    VanillaOption option(payOff, Expiry);

    // fromPayoffBridge(bridge, Spot);

    double result = SimpleMonteCarlo5(option,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "Price of Option = " 
          << result
          << endl;

    return 0;
}