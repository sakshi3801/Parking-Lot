#pragma once
#include <iostream>

using namespace std;

class PaymentProcessor {
    public: virtual void processPayment(int amount);
            virtual ~PaymentProcessor() = default;
};