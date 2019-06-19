#include <iostream>
#include "options/PayOff2.h"
#include "options/simplemc3.h"

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

    PayOffCall callPayoff(Strike);
    PayOffPut putPayoff(Strike);

    double resultCall = SimpleMonteCarlo3(callPayoff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    double resultPut = SimpleMonteCarlo3(putPayoff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "Price of Option[call] = " 
          << resultCall
          << endl;

    cout << "Price of Option[put] = " 
          << resultPut
          << endl;

    return 0;
}