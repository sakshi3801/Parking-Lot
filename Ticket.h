#pragma once
#include <iostream>
#include "Vehicle.h"
#include "ParkingSpot.h"

using namespace std;

class Ticket {
    private: int ticketId;
             long long entryTime;
             Vehicle *v;
             ParkingSpot *spot;

    public: Ticket(int ticketId, long long entryTime, Vehicle *v, ParkingSpot *spot);
    
            long long getDuration(long long exitTime);            
};