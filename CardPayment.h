#pragma once
#include "PaymentProcessor.h"

using namespace std;

class CardPayment: public PaymentProcessor {
    public: void processPayment(int amount);
};