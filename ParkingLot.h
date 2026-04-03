#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "IParkingLot.h"
#include <map>
#include <vector>

class ParkingLot: public IParkingLot {
    private: map<VehicleType, vector<ParkingSpot*>> spots;
    public:
            ParkingSpot* findParkingSpot(Vehicle &v) override;
            void vacateSpot(ParkingSpot &spot) override;
            void addSpots(VehicleType t, ParkingSpot *spot) override;
};
