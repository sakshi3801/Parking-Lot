#pragma once
#include <iostream>

using namespace std;

class PaymentProcessor {
    public: virtual void processPayment(int amount) = 0;
            virtual ~PaymentProcessor() = default;
};