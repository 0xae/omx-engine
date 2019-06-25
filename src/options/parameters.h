#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <memory>
using std::unique_ptr;

class ParametersInner
{
public:
    ParametersInner(){}
    virtual ~ParametersInner() {}

    virtual unique_ptr<ParametersInner> Clone() const=0;
    virtual double Integral(double time1, double time2) const=0;
    virtual double IntegralSquare(double time1, double time2) const=0;
};

class Parameters
{
public:
    Parameters(const ParametersInner &inner);
    Parameters(const Parameters &original);
    Parameters& operator=(const Parameters &original);
    virtual ~Parameters();

    double Integral(double time1, double time2) const;
    double IntegralSquare(double time1, double time2) const;
    double Mean(double time1, double time2) const;
    double RootMeanSquare(double time1, double time2) const;
private:
    unique_ptr<ParametersInner> parametersBridge;
};

class ParametersConstant : public ParametersInner
{
public:
    ParametersConstant(double constant);
    ~ParametersConstant(){}

    virtual unique_ptr<ParametersInner> Clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
private:
    double Constant;
    double ConstantSquare;
};


#endif
