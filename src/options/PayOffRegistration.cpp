#include "PayOffConstruct.h"

namespace 
{
    PayOffHelper<PayOffCall> RegisterCall("call");

    PayOffHelper<PayOffPut> RegisterPut("put");
}