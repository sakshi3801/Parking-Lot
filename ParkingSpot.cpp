#include "ParkingSpot.h"
#include "SpotType.h"
#include "Vehicle.h"
#include "VehicleType.h"

ParkingSpot::ParkingSpot(string spotId, SpotType spotType) : spotId(spotId), spotType(spotType), vehicle(nullptr), isEmpty(true) {}

void ParkingSpot::park(Vehicle &v) {
    if (!this->isAvailable() || !isMatch(v)) {
        return;
    }
    this->vehicle = &v;
    this->isEmpty = false;
}

void ParkingSpot::remove() {
    this->vehicle = nullptr;
    this->isEmpty = true;
}

bool ParkingSpot::isAvailable() {
    return this->isEmpty;
}

bool ParkingSpot::isMatch(Vehicle &v) {
    VehicleType t = v.getType();
    switch (t)
    {
    case VehicleType::BIKE:
         return this->spotType == SpotType::SMALL;
    
    case VehicleType::CAR:
        return this->spotType == SpotType::LARGE;
    }
    return false;
}

string ParkingSpot::getSpotId() {
    return this->spotId;
}