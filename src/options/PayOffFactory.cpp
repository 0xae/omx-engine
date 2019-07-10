#include <iostream>
#include "PayOffFactory.h"

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction) 
{
    pair<string,CreatePayOffFunction> entry(PayOffId,CreatorFunction);
    TheCreatorFunctions.insert(entry);
}


unique_ptr<PayOff> PayOffFactory::CreatePayOff(string PayOffId, double Strike)
{
    map<string, CreatePayOffFunction>::const_iterator
        i = TheCreatorFunctions.find(PayOffId);

    if (i == TheCreatorFunctions.end()) {
        // std::cout << PayOffId
        // << " is an unknown payoff" << std::endl;
        return NULL;
    }

    return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}

