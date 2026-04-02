#include "HourlyPaymentStrategy.h"

using namespace std;

int HourlyPaymentStrategy::calculate(long long duration, VehicleType t) {
    int hours = duration / 60;
    int amount;
    switch (t)
    {
    case VehicleType::BIKE:
         amount = 20 * hours;
         break;
    
    case VehicleType::CAR:
         amount = 40 * hours;
         break;
    } 
    return amount;
}