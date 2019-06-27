#include <iostream>

#include "options/simplemc7.h"
#include "options/mcstatistics.h"
#include "options/convergencetable.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

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
    ConvergenceTable resumeTable(gatherer.Clone());

    SimpleMonteCarlo7(option,
        Spot,
        VolParam,
        rParam,
        NumberOfPaths,
        resumeTable
    );

    vector<vector<double>> results = resumeTable.GetResultsSoFar();

    cout << "Price of option calls: " << endl;

    for (unsigned int i=0; i<results.size(); i++) {
        for (unsigned int j=0; j<results[i].size(); j++) {
            cout << "\t" << i << " => "
                << results[i][j]
                << ";"
                << endl;
        }
    }

    return 0;
}

