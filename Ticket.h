#pragma once
#include <iostream>

class Vehicle;
class ParkingSpot;

using namespace std;

class Ticket {
    private: int ticketId;
             long long entryTime;
             Vehicle *v;
             ParkingSpot *spot;

    public: Ticket(int ticketId, long long entryTime, Vehicle *v, ParkingSpot *spot);
    
            long long getDuration(long long exitTime);            
};