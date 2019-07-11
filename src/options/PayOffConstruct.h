#ifndef PAYOFF_CONSTRUCT
#define PAYOFF_CONSTRUCT

#include <iostream>
#include <string>
#include "PayOff2.h"
#include "PayOffFactory.h"

using std::string;

template <class T>
class PayOffHelper
{
public:
    PayOffHelper(string);
    static unique_ptr<PayOff> Create(double);
};

template <class T>
PayOffHelper<T>::PayOffHelper(string id) {
    PayOffFactory &theFactory = PayOffFactory::Instance();
    theFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}

template<class T>
unique_ptr<PayOff> PayOffHelper<T>::Create(double Strike) {
    return unique_ptr<PayOff> (new T(Strike));
}

#endif
