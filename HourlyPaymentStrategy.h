#pragma once
#include <map>
#include "PaymentStrategy.h"

class HourlyPaymentStrategy: public PaymentStrategy {
    private: map<VehicleType, int> &hourlyRates;
    public: 
            HourlyPaymentStrategy(map<VehicleType, int> &hourlyRates);
            int calculate(long long duration, VehicleType t);
};