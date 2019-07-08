#include <iostream>
#include "arrays.h"
#include "binomialtree.h"
#include "normals.h"
#include "parameters.h"
#include "PayOff2.h"
#include "payoffbridge.h"
#include "PayOffForward.h"
#include "treeproduct.h"
#include "treeamerican.h"
#include "treeeuropean.h"
#include "BlackScholesFormulas.h"

using std::cout;
using std::cin;

int main(int argc, char const *argv[]) {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long Steps;
    
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

    cout << "\nNumber of steps: ";
    cin >> Steps;

    PayOffCall thePayOff(Strike);

    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    TreeEuropean europeanOption(Expiry, thePayOff);
    // TreeAmerican americanOption(Expiry, thePayOff);

    SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, 
                            Steps, Expiry);

    double euroPrice = theTree.GetThePrice(europeanOption);
    // double americanPrice = theTree.GetThePrice(americanOption);


    cout << "euro price = "
         << euroPrice 
         // << "\namerican price = "
         // << americanPrice
         << "\n=====\n";

    return 0;
}

