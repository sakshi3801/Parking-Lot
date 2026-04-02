#pragma once
#include "PaymentStrategy.h"

class FixedPaymentStrategy: public PaymentStrategy {
    public: int calculate(long long duration, VehicleType t);
};