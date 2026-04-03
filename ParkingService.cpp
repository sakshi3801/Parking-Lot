#include "ParkingService.h"

ParkingService::ParkingService(IParkingLot &iParkingLot, TicketService &ticketService, CheckoutService &checkoutService):
iParkingLot(iParkingLot), ticketService(ticketService), checkoutService(checkoutService) {}

bool ParkingService::parkVehicle(Vehicle &vehicle) {
    ParkingSpot *spot = iParkingLot.findParkingSpot(vehicle);
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
    iParkingLot.vacateSpot(*spot);
    vehicle.clearParkingState();
    return true;
}
