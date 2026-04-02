#include "ParkingLot.h"

ParkingLot::ParkingLot(std::vector<ParkingSpot*> &carSpots, std::vector<ParkingSpot*> &bikeSpots): carSpots(carSpots), bikeSpots(bikeSpots) {}

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

void ParkingLot::vacateSpot(ParkingSpot &spot) {
    spot.remove();
}
