#pragma once
#include <iostream>
#include "Vehicle.h"
#include "SpotType.h"

using namespace std;

class ParkingSpot {
    private: string spotId;
             Vehicle *vehicle;
             bool isEmpty;
             SpotType spotType;
    public: ParkingSpot(string spotNum, SpotType s);
            void park(Vehicle &v);
            void remove();
            bool isAvailable();
            bool isMatch(Vehicle &v);
            string getSpotId();
};