#pragma once
#include <iostream>
#include "PaymentStrategy.h"
#include "PaymentProcessor.h"
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "Ticket.h"
#include <vector>

using namespace std;

class ParkingLot {
    static int ticketCounter;
    private: PaymentStrategy &strategy;
             PaymentProcessor &processor;
             vector<ParkingSpot*> &carSpots;
             vector<ParkingSpot*> &bikeSpots;
    
    public: ParkingLot(PaymentStrategy &strategy, PaymentProcessor &processor, vector<ParkingSpot*> &carSpots, vector<ParkingSpot*> &bikeSpots);
            ParkingSpot* findParkingSpot(Vehicle &v);
            void parkVehicle(Vehicle &v);
            void removeVehicle(Vehicle &v);
            void generateTicket(Vehicle &v);
            void process(long long duration, VehicleType type);
};