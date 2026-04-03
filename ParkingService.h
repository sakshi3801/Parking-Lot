#pragma once
#include "CheckoutService.h"
#include "TicketService.h"
#include "IParkingLot.h"
class ParkingService {
    private: IParkingLot &iParkingLot;
             TicketService &ticketService;
             CheckoutService &checkoutService;

    public: ParkingService(IParkingLot &iParkingLot, TicketService &ticketService, CheckoutService &checkoutService);
            bool parkVehicle(Vehicle &vehicle);
            bool removeVehicle(Vehicle &vehicle);
};
