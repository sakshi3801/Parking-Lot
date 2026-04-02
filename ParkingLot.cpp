#pragma once
#include "ParkingLot.h"
#include <ctime>
#include <math.h>

using namespace std;

int ParkingLot::ticketCounter = 0;

ParkingLot::ParkingLot(PaymentStrategy &strategy, PaymentProcessor &processor, vector<ParkingSpot*> &carSpots, vector<ParkingSpot*> &bikeSpots):
strategy(strategy), processor(processor), carSpots(carSpots), bikeSpots(bikeSpots) {}

ParkingSpot* ParkingLot::findParkingSpot(Vehicle &v) {
    if (v.getType() == VehicleType::CAR) {
        for (int i=0; i<this->carSpots.size(); i++) {
            ParkingSpot *spot = carSpots[i];
            if (spot->isAvailable()) return spot;
        }
    } else {
        for (int i=0; i<this->bikeSpots.size(); i++) {
            ParkingSpot *spot = bikeSpots[i];
            if (spot->isAvailable()) return spot;
        }
    }
    return nullptr;
}

void ParkingLot::parkVehicle(Vehicle &v) {
    ParkingSpot* spot = this->findParkingSpot(v);
    if (spot == nullptr) {
        cout << "No parking spot available";
        return;
    }
    spot->park(v);
    v.setSpot(spot);
    this->generateTicket(v);
    cout << "Vehicle has been parked at " << spot->getSpotId();
}

void ParkingLot::removeVehicle(Vehicle &v) {
    ParkingSpot *spot = v.getSpot();
    Ticket *t = v.getTicket();
    if (!spot || !t) return;
    long long duration = t->getDuration((long long)time(nullptr));
    this->process(duration, v.getType());
    spot->remove();
}

void ParkingLot::generateTicket(Vehicle &v) {
    long long entryTime = (long long)time(nullptr);
    Ticket *t = new Ticket(++ticketCounter, entryTime, &v, v.getSpot());
    v.assignTicket(*t);
}

void ParkingLot::process(long long duration, VehicleType type) {
    int amount = this->strategy.calculate(duration, type);
    this->processor.processPayment(amount);
}


