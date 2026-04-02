#include "CheckoutService.h"
#include "Ticket.h"
#include <ctime>

CheckoutService::CheckoutService(PaymentProcessor &processor, PaymentStrategy &strategy): processor(processor), strategy(strategy) {};

void CheckoutService::process(Vehicle &vehicle) {
    Ticket *ticket = vehicle.getTicket();
    if (ticket == nullptr) {
        return;
    }

    long long exitTime = static_cast<long long>(time(nullptr));
    long long duration = ticket->getDuration(exitTime);
    int amount = this->strategy.calculate(duration, vehicle.getType());
    this->processor.processPayment(amount);
}