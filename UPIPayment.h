#pragma once
#include "PaymentProcessor.h"

using namespace std;

class UPIPayment: public PaymentProcessor {
    public: void processPayment(int amount);
};