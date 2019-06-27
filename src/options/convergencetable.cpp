#include "convergencetable.h"

using std::vector;
using std::unique_ptr;

ConvergenceTable::ConvergenceTable(unique_ptr<StatisticsMC> ptr) {
    // Inner = std::move(ptr);
    StoppingPoint=2;
    PathsDone=0;
}

unique_ptr<StatisticsMC> ConvergenceTable::Clone() const {
    // ??? 
    return unique_ptr<StatisticsMC>(new ConvergenceTable(*this));
}

void ConvergenceTable::DumpOneResult(double result) {
    Inner->DumpOneResult(result);    
    PathsDone++;

    if (PathsDone==StoppingPoint) {
        StoppingPoint *= 2;
        vector<vector<double>> tmpResults(Inner->GetResultsSoFar());
        unsigned long count=tmpResults.size();

        for (unsigned long i=0; i<count; i++) {
            tmpResults[i].push_back(PathsDone);
            ResultsSoFar.push_back(tmpResults[i]);
        }
    }
}


vector<vector<double>> ConvergenceTable::GetResultsSoFar() const {
    vector<vector<double>> tmp(ResultsSoFar);
    
    if (PathsDone*2 != StoppingPoint) {
        vector<vector<double>> tmpResults(Inner->GetResultsSoFar());
        unsigned long count=tmpResults.size();

        for (unsigned long i=0; i<count; i++) {
            tmpResults[i].push_back(PathsDone);
            tmp.push_back(tmpResults[i]);
        }
    }

    return tmp;
}


