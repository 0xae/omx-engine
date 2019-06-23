#include <iostream>
#include "options/PayOff2.h"
#include "options/simplemc4.h"

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

    PayOffCall payOffCall(Strike);
    VanillaOption option(payOffCall, Expiry);

    double result = SimpleMonteCarlo4(option,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "Price of Call option = " 
          << result
          << endl;

    VanillaOption option2(option);

    result = SimpleMonteCarlo4(option2,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );    

    cout << "Price of Call option::2 = " 
          << result
          << endl;

    PayOffPut payOffPut(Strike);
    VanillaOption option3(payOffPut, Strike);

    result = SimpleMonteCarlo4(option3,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );    

    cout << "Price of Put option::3 = " 
          << result
          << endl;


    return 0;
}