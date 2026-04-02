#pragma once
#include "Vehicle.h"
#include <iostream>

using namespace std;

class TicketService {
    static int ticketCounter;
    public: void generateTicket(Vehicle &v);
};