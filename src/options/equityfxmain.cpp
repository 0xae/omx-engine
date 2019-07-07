#include <iostream>
#include "parkmiller.h"
#include "mcstatistics.h"
#include "convergencetable.h"
#include "antithetic.h"
#include "pathdependentasian.h"
#include "exoticbsengine.h"

using std::cout;
using std::cin;

int main(int argc, char const *argv[]) {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long NumberOfPaths;
    unsigned NumberOfDates;
    
    cout << "\nEnter expiry: ";
    cin >> Expiry;

    cout << "\nStrike: ";
    cin >> Strike;

    cout << "\nEnter spot: ";
    cin >> Spot;

    cout << "\nEnter vol: ";
    cin >> Vol;

    cout << "\nr: ";
    cin >> r;

    cout << "\nd: ";
    cin >> d;

    cout << "Number of dates: ";
    cin >> NumberOfDates;

    cout << "\nNumber of paths: ";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);
    MJArray times(NumberOfDates);

    for (int i=0; i<NumberOfDates; ++i) {
        times[i]=(i+1.0) * Expiry/NumberOfDates;
    }

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);


    return 0;
}

