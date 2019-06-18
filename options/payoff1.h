#ifndef PAYOFF_H
#define PAYOFF_H

enum OptionType {call, put};

class PayOff {

public:
    PayOff(double Strike_, OptionType TheOptionsType_);
    double Calculate(double Spot) const;

private:
    double Strike;
    OptionType TheOptionType;
};

#endif
