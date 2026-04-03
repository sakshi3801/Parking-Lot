#include "FixedPaymentStrategy.h"

using namespace std;

FixedPaymentStrategy::FixedPaymentStrategy(map<VehicleType, int> &fixedRates): fixedRates(fixedRates) {}
int FixedPaymentStrategy::calculate(long long duration, VehicleType t) {
    return fixedRates[t];
}