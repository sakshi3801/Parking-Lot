#include "HourlyPaymentStrategy.h"

using namespace std;

HourlyPaymentStrategy::HourlyPaymentStrategy(map<VehicleType, int> &hourlyRates): hourlyRates(hourlyRates) {}
int HourlyPaymentStrategy::calculate(long long duration, VehicleType t) {
    int hours = duration / 3600;
    return hourlyRates[t] * hours;
}