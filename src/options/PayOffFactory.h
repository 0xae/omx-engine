#ifndef PAYOFF_FACTORY_H
#define PAYOFF_FACTORY_H

#include <map>
#include <string>
#include <memory>
#include "PayOff2.h"

using std::unique_ptr;
using std::string;
using std::map;
using std::pair;

class PayOffFactory {
public:
    typedef unique_ptr<PayOff> (*CreatePayOffFunction)(double);

    static PayOffFactory& Instance();
    void RegisterPayOff(string, CreatePayOffFunction);
    unique_ptr<PayOff> CreatePayOff(string PayOffId, double Strike);

    ~PayOffFactory() {}
private:
    map<string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory() {}
    PayOffFactory(const PayOffFactory&) {}
    PayOffFactory& operator=(const PayOffFactory &) {
        return *this;
    }
};

#endif