#include <iostream>
#include "options/simplemc8.h"

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

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);

    SimpleMonteCarlo8(option,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths,
        gathererTwo,
        GenTwo
    );

    vector<vector<double>> results = gathererTwo.GetResultsSoFar();

    cout << "Price of Put: " << endl;

    for (unsigned long i=0; i<results.size(); ++i) {
        for (unsigned long j=0; j<results[i].size(); j++) {
            cout << "==> " 
                << results[i][j]
                << endl;
        }
    }

    return 0;
}