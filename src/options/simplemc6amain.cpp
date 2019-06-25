#include <iostream>
#include "options/simplemc6a.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
 
    cout << "\nEnter expiry: ";
    cin >> Expiry;
 
    cout << "\nEnter strike: ";
    cin >> Strike;
 
    cout << "\nEnter spot: ";
    cin >> Spot;
 
    cout << "\nEnter vol: ";
    cin >> Vol;
 
    cout << "\nr: ";
    cin >> r;

    cout << "\nNumber of paths: ";
    cin >> NumberOfPaths;

    PayOffPut payOff(Strike);
    VanillaOption option(payOff, Expiry);

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    double result = SimpleMonteCarlo6a(option,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths
    );

    cout << "Price of Call option = " 
          << result
          << endl;

    return 0;
}