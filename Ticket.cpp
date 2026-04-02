#include "Ticket.h"
#include "ParkingSpot.h"
#include "Vehicle.h"

Ticket::Ticket(int ticketId, long long entryTime, Vehicle *v, ParkingSpot *spot): ticketId(ticketId), entryTime(entryTime), v(v), spot(spot) {}

long long Ticket::getDuration(long long exitTime) {
    return exitTime - this->entryTime;
}