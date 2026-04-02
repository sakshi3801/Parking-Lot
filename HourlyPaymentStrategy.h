#pragma once
#include "PaymentStrategy.h"

class HourlyPaymentStrategy: public PaymentStrategy {
    public: int calculate(long long duration, VehicleType t);
};