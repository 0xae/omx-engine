#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <memory>
#include <iostream>

class StatisticsMC
{
public:
    StatisticsMC() {}
    virtual ~StatisticsMC() {
        // std::cout << "~StatisticsMC()" 
        //     << std::endl;
    }

    virtual void DumpOneResult (double result)=0;
    virtual std::vector<std::vector<double>> GetResultsSoFar() const=0;
    virtual std::unique_ptr<StatisticsMC> Clone() const=0;
};

class StatisticsMean : public StatisticsMC
{
public:
    StatisticsMean();

    virtual void DumpOneResult (double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    virtual std::unique_ptr<StatisticsMC> Clone() const;

private:
    double RunningSum;
    unsigned long PathsDone;
};

#endif