#include "mcstatistics.h"

using std::vector;
using std::unique_ptr;

StatisticsMean::StatisticsMean() 
    : RunningSum(0.0), PathsDone(0UL) {
}

void StatisticsMean::DumpOneResult(double result) {
    PathsDone++;
    RunningSum += result;
}

vector<vector<double>> StatisticsMean::GetResultsSoFar() const {
    vector<vector<double>> Results(1);
    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsDone;

    return Results;
}

unique_ptr<StatisticsMC> StatisticsMean::Clone() const {
    return std::unique_ptr<StatisticsMC>(new StatisticsMean(*this));
}
