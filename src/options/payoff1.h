#ifndef PAYOFF_H
#define PAYOFF_H


class PayOff {

public:
    enum OptionType {call, put};
    PayOff(double Strike_, OptionType TheOptionsType_);
    double Calculate(double Spot) const;

private:
    double Strike;
    OptionType TheOptionType;
};

#endif
