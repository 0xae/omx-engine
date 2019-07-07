#include <vector>
#include "treeproduct.h"
#include "parameters.h"
#include "arrays.h"

using std::vector;
using std::pair;

class SimpleBinomialTree {
public:
    SimpleBinomialTree(double Spot_,
                 const Parameters &r_,
                 const Parameters &d_,
                 double Volatility_,
                 unsigned long Steps_,
                 double Time);

    ~SimpleBinomialTree() {}

    double GetThePrice(const TreeProduct &TheProduct);

protected:
    void BuildTree();

private:
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;

    vector<vector<pair<double,double>>> TheTree;
    MJArray Discounts;
};
