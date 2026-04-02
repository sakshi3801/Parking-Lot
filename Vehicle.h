#pragma once
#include <iostream>
#include "VehicleType.h"

class Ticket;
class ParkingSpot;

class Vehicle {
    private: int vehicleNumber;
             VehicleType type;
             ParkingSpot *spot;
             Ticket *ticket;

    public: Vehicle(int num, VehicleType t);
            int getNumber();
            VehicleType getType();
            void setSpot(ParkingSpot *spot);
            ParkingSpot* getSpot();
            void assignTicket(Ticket &ticket);
            Ticket* getTicket();
            void clearParkingState();
};