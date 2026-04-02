#pragma once
#include "PaymentProcessor.h"
#include "PaymentStrategy.h"
#include "Vehicle.h"

class CheckoutService {
    private: PaymentProcessor &processor;
             PaymentStrategy &strategy;
    public: CheckoutService(PaymentProcessor &processor, PaymentStrategy &strategy);
            void process(Vehicle &vehicle);
};
