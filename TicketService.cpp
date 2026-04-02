#include "TicketService.h"
#include "Ticket.h"
#include <ctime>

int TicketService::ticketCounter = 0;

void TicketService::generateTicket(Vehicle &v) {
    long long entryTime = (long long)time(nullptr);
    Ticket *t = new Ticket(++ticketCounter, entryTime, &v, v.getSpot());
    v.assignTicket(*t);
}