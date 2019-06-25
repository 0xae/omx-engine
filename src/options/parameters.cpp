#include "parameters.h"

/**
** class Parameters
**/
Parameters::Parameters(const ParametersInner &inner) {
    parametersBridge = inner.Clone();
}

Parameters::Parameters(const Parameters &original) {
    parametersBridge = (original.parametersBridge)->Clone();
}

double Parameters::Integral(double time1, double time2) const {
    return parametersBridge->Integral(time1,time2);
}

double Parameters::IntegralSquare(double time1, double time2) const {
    return parametersBridge->IntegralSquare(time1,time2);
}

Parameters& Parameters::operator=(const Parameters& original) {
    if (this != &original) {
        delete parametersBridge.release();
        parametersBridge = (original.parametersBridge)->Clone();
    }
    return *this;
}

Parameters::~Parameters() {
}

double Parameters::Mean(double time1, double time2) const {
    double total = Integral(time1,time2);
    return total/(time2-time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const {
    double total = IntegralSquare(time1,time2);
    return total/(time2-time1);
}

/**
** class ParametersConstant
**/
ParametersConstant::ParametersConstant(double constant) {
    Constant = constant;
    ConstantSquare = Constant*Constant;
}

unique_ptr<ParametersInner> ParametersConstant::Clone() const {
    return unique_ptr<ParametersInner>(new ParametersConstant(*this));
}

double ParametersConstant::Integral(double time1, double time2) const {
    return (time2-time1)*Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const {
    return (time2-time1)*ConstantSquare;
}
