#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
#include <vector>

class ParkingLot {
    private: std::vector<ParkingSpot*> &carSpots;
             std::vector<ParkingSpot*> &bikeSpots;
    
    public: ParkingLot(std::vector<ParkingSpot*> &carSpots, std::vector<ParkingSpot*> &bikeSpots);
            ParkingSpot* findParkingSpot(Vehicle &v);
            void vacateSpot(ParkingSpot &spot);
};