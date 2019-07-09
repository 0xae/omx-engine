#include <iostream>
#include <cmath>
#include "normals.h"
#include "bisection.h"
#include "BlackScholesFormulas.h"
#include "bscall.h"

using std::cout;
using std::cin;

int main(int argc, char const *argv[]) {
    double Expiry;
    double Strike;
    double Spot;
    double r;
    double d;
    double Price;
    
    cout << "expiry= ";
    cin >> Expiry;

    cout << "\nStrike= ";
    cin >> Strike;

    cout << "\nspot= ";
    cin >> Spot;

    cout << "\nPrice= ";
    cin >> Price;

    cout << "\nr= ";
    cin >> r;

    cout << "\nd= ";
    cin >> d;

    double low, high, tolerance;

    cout << "\nlow guess= ";
    cin >> low;

    cout << "\nhigh guess= ";
    cin >> high;

    cout << "\ntolerance= ";
    cin >> tolerance;

    BSCall theCall(r,d,Expiry,Spot,Strike);

    double vol=Bisection(Price,low,high,tolerance,theCall);

    double PriceTwo=BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout << "====\n"
        << "vol=" << vol
        << "\npricetwo=" << PriceTwo
        ;

    return 0;
}

