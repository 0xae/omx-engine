#ifndef PAYOFF_H
#define PAYOFF_H


class PayOff {

public:
    PayOff() {};
    virtual double Calculate(double Spot) const=0;
    virtual ~PayOff() {};
};

class PayOffPut : public PayOff {
public:
    PayOffPut(double Strike_);
    virtual double Calculate(double Spot) const;
    virtual ~PayOffPut(){}
private:
    double Strike;
};

class PayOffCall : public PayOff {
public:
    PayOffCall(double Strike_);
    virtual double Calculate(double Spot) const;
    virtual ~PayOffCall(){}
private:
    double Strike;
};

#endif
