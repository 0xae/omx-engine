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

    int optionType;
    cout << "\nSelect option type (0: put, 1: call): ";
    cin >> optionType;
    PayOff *ptr;
    if (optionType==0) {
        ptr = new PayOffPut(Strike);
    } else {
        ptr = new PayOffCall(Strike);
    }

    double result = SimpleMonteCarlo3(*ptr,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "Price of Option = " 
          << result
          << endl;

    delete ptr;
    return 0;
}