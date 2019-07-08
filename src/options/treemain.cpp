#include <iostream>
#include <cmath>
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
    TreeAmerican americanOption(Expiry, thePayOff);

    SimpleBinomialTree theTree(Spot, rParam, dParam, 
                               Vol, Steps, Expiry);

    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);

    cout << "\n=====\n"
         << "euro price = "
         << euroPrice 
         << "\namerican price = "
         << americanPrice 
         << "\n";

    double BSPrice = BlackScholesCall(Spot, Strike, r, 
                                      d, Vol, Expiry);

    cout << "BS formula euro price: " 
         << BSPrice
         << "\n";

    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry, forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree = "
         << forwardPrice
         << "\n";

    double actualForwardPrice = exp(-r*Expiry) * (Spot*exp((r-d)*Expiry)-Strike);
    cout << "actual forward price = "
         << actualForwardPrice
         << "\n";

    // now we redo the trees with one more step
    Steps++;

    SimpleBinomialTree theNewTree(Spot, rParam, dParam, Vol,
                                  Steps, Expiry);

    double euroNewPrice = theNewTree.GetThePrice(europeanOption);
    double americanNewPrice = theNewTree.GetThePrice(americanOption);
    double forwardNewPrice = theNewTree.GetThePrice(forward);

    cout << "\n=====\n"
        << "**euro price = "
        << euroNewPrice 
        << "\n**american price = "
        << americanNewPrice
        << "\n**forward price by tree = "
        << forwardNewPrice
        << "\n=====\n";

    double avgEuro = 0.5*(euroPrice+euroNewPrice);
    double avgAmer = 0.5*(americanPrice+americanNewPrice);
    double avgForward = 0.5*(forwardPrice+forwardNewPrice);

    cout << "\n=====\n"
        << "avg euro price = "
        << avgEuro 
        << "\navg american price = "
        << avgAmer
        << "\navg forward price by tree = "
        << avgForward
        << "\n=====\n";    

    return 0;
}

