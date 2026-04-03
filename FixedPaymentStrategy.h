#pragma once
#include <map>
#include "PaymentStrategy.h"

class FixedPaymentStrategy: public PaymentStrategy {
    private: map<VehicleType, int> &fixedRates;
    public: 
            FixedPaymentStrategy(map<VehicleType, int> &fixedRates);
            int calculate(long long duration, VehicleType t);
};