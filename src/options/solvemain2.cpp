#include <iostream>
#include <cmath>
#include "normals.h"

#include "BlackScholesFormulas.h"
#include "bscalltwo.h"
#include "NewtonRaphson.h"

using std::cout;
using std::cin;

int main(int argc, char const *argv[]) {
    double Expiry;
    double Strike;
    double Price;
    double Spot;
    double r;
    double d;
    
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

    double start, tolerance;

    cout << "\nstart guess= ";
    cin >> start;

    cout << "\ntolerance= ";
    cin >> tolerance;

    BSCallTwo theCall(r,d,Expiry,Spot,Strike);

    double vol=NewtonRaphson<BSCallTwo, &BSCallTwo::Price,
                             &BSCallTwo::Vega>(Price, start, 
                                               tolerance,theCall);

    double PriceTwo=BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

    cout << "====\n"
        << "vol=" << vol
        << "\npricetwo=" << PriceTwo
        ;

    return 0;
}

