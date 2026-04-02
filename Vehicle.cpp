#include "Vehicle.h"

Vehicle::Vehicle(int num, VehicleType t) {
    this->vehicleNumber = num;
    this->type = t;
}

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