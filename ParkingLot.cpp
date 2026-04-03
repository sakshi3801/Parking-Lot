#include "ParkingLot.h"

ParkingSpot* ParkingLot::findParkingSpot(Vehicle &v) {
    VehicleType type = v.getType();
    if (spots[type].size() == 0) return nullptr;
    for (int i=0; i<spots[type].size(); i++) {
        if (spots[type][i]->isAvailable()) return spots[type][i];
    }
    return nullptr;
}

void ParkingLot::vacateSpot(ParkingSpot &spot) {
    spot.remove();
}

void ParkingLot::addSpots(VehicleType t, ParkingSpot *spot) {
    spots[t].push_back(spot);
}
