#include "ParkingService.h"

ParkingService::ParkingService(ParkingLot &parkingLot, TicketService &ticketService, CheckoutService &checkoutService):
parkingLot(parkingLot), ticketService(ticketService), checkoutService(checkoutService) {}

bool ParkingService::parkVehicle(Vehicle &vehicle) {
    ParkingSpot *spot = parkingLot.findParkingSpot(vehicle);
    if (spot == nullptr) {
        return false;
    }

    spot->park(vehicle);
    vehicle.setSpot(spot);
    ticketService.generateTicket(vehicle);
    return true;
}

bool ParkingService::removeVehicle(Vehicle &vehicle) {
    ParkingSpot *spot = vehicle.getSpot();
    if (spot == nullptr || vehicle.getTicket() == nullptr) {
        return false;
    }

    checkoutService.process(vehicle);
    parkingLot.vacateSpot(*spot);
    vehicle.clearParkingState();
    return true;
}
