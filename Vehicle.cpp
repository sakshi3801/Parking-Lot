#include "Vehicle.h"
#include "ParkingSpot.h"
#include "Ticket.h"

Vehicle::Vehicle(int num, VehicleType t): vehicleNumber(num), type(t), spot(nullptr), ticket(nullptr) {}

int Vehicle::getNumber() {
    return this->vehicleNumber;
}

VehicleType Vehicle::getType() {
    return this->type;
}

void Vehicle::setSpot(ParkingSpot *s) {
    this->spot = s;
}

ParkingSpot* Vehicle::getSpot() {
    return this->spot;
}

void Vehicle::assignTicket(Ticket &ticket) {
    this->ticket = &ticket;
}

Ticket* Vehicle::getTicket() {
    return this->ticket;
}

void Vehicle::clearParkingState() {
    this->spot = nullptr;
    this->ticket = nullptr;
}