#include <memory>
#include <iostream>

#ifndef PAYOFF2_H
#define PAYOFF2_H

using std::unique_ptr;
using std::cout;
using std::endl;

class PayOff {
public:
    PayOff() {};
    virtual double Calculate(double Spot) const=0;
    virtual unique_ptr<PayOff> Clone() const=0;
    virtual ~PayOff() {};
};

class PayOffPut : public PayOff {
public:
    PayOffPut(double Strike_);
    virtual double Calculate(double Spot) const;
    virtual unique_ptr<PayOff> Clone() const;
    virtual ~PayOffPut(){
        // cout << "~PayOffPut()" 
        //      << endl;
    }

private:
    double Strike;
};

class PayOffCall : public PayOff {
public:
    PayOffCall(double Strike_);
    virtual double Calculate(double Spot) const;
    virtual unique_ptr<PayOff> Clone() const;
    virtual ~PayOffCall(){
        // cout << "~PayOffCall()" 
        //      << endl;
    }

private:
    double Strike;
};

#endif
