#include "FixedPaymentStrategy.h"

using namespace std;

int FixedPaymentStrategy::calculate(long long duration, VehicleType t) {
    int amount;
    switch (t)
    {
    case VehicleType::BIKE:
         amount = 50;
         break;
    
    case VehicleType::CAR:
         amount = 100;
         break;
    } 
    return amount;
}