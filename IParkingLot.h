#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
#include <map>
#include <vector>

using namespace std;


class IParkingLot {
    public:
            virtual ParkingSpot* findParkingSpot(Vehicle &v) = 0;
            virtual void vacateSpot(ParkingSpot &spot) = 0;
            virtual void addSpots(VehicleType t, ParkingSpot *spot) = 0;
            virtual ~IParkingLot() = default;
};