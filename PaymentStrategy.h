#pragma once
#include <iostream>
#include "VehicleType.h"

using namespace std;

class PaymentStrategy {
    public: virtual int calculate(long long duration, VehicleType t) = 0;
            virtual ~PaymentStrategy() = default;
};