#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H

#include <vector>
#include <memory>
#include <iostream>
#include "mcstatistics.h"

using std::vector;
using std::unique_ptr;

class ConvergenceTable : public StatisticsMC
{
public:
    ConvergenceTable(unique_ptr<StatisticsMC> ptr);

    virtual void DumpOneResult (double result);
    virtual vector<vector<double>> GetResultsSoFar() const;
    virtual unique_ptr<StatisticsMC> Clone() const;

private:
    unique_ptr<StatisticsMC> Inner;
    vector<vector<double>> ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};

#endif