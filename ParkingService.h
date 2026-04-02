#pragma once
#include "CheckoutService.h"
#include "ParkingLot.h"
#include "TicketService.h"

class ParkingService {
    private: ParkingLot &parkingLot;
             TicketService &ticketService;
             CheckoutService &checkoutService;

    public: ParkingService(ParkingLot &parkingLot, TicketService &ticketService, CheckoutService &checkoutService);
            bool parkVehicle(Vehicle &vehicle);
            bool removeVehicle(Vehicle &vehicle);
};
