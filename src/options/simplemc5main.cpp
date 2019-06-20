#include <iostream>
#include "options/PayOff2.h"
#include "options/simplemc3.h"
#include "options/doubledigital.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    double Expiry;
    double low, high;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
 
    cout << "\nEnter expiry: ";
    cin >> Expiry;
 
    cout << "\nEnter low barrier: ";
    cin >> low;

    cout << "\nEnter high barrier: ";
    cin >> high;
 
    cout << "\nEnter spot: ";
    cin >> Spot;
 
    cout << "\nEnter vol: ";
    cin >> Vol;
 
    cout << "\nr: ";
    cin >> r;

    cout << "\nNumber of paths: ";
    cin >> NumberOfPaths;

    PayOffDoubleDigital payOff(low, high);

    double result = SimpleMonteCarlo3(payOff,
        Expiry,
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