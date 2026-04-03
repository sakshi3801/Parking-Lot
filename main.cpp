#include <iostream>
#include "ParkingLot.h"
#include "ParkingSpot.h"
#include "PaymentStrategy.h"
#include "PaymentProcessor.h"
#include "Vehicle.h"
#include "HourlyPaymentStrategy.h"
#include "FixedPaymentStrategy.h"
#include "CardPayment.h"
#include "UPIPayment.h"
#include "VehicleType.h"
#include "TicketService.h"
#include "CheckoutService.h"
#include "ParkingService.h"
#include <map>

using namespace std;

int main() {
    map<VehicleType, int> hourlyRates = {{VehicleType::BIKE, 20}, {VehicleType::CAR, 40}};
    map<VehicleType, int> fixedRates = {{VehicleType::BIKE, 50}, {VehicleType::CAR, 100}};
    
    PaymentStrategy *strategy = new HourlyPaymentStrategy(hourlyRates);
    PaymentProcessor *processor = new CardPayment();
    TicketService *ticketService = new TicketService();
    CheckoutService *checkoutService = new CheckoutService(*processor, *strategy);
    vector<ParkingSpot*> carSpots;
    vector<ParkingSpot*> bikeSpots;
    string idCar = "car";
    string idBike = "bike";

    ParkingLot *parkingLot = new ParkingLot();
    for (int i=0; i<5; i++) {
        string newId = idCar + std::to_string(i);
        ParkingSpot *spot = new ParkingSpot(newId, SpotType::LARGE);
        parkingLot->addSpots(VehicleType::CAR, spot);
    }
    for (int i=0; i<5; i++) {
        string newId = idBike + std::to_string(i);
        ParkingSpot *spot = new ParkingSpot(newId, SpotType::SMALL);
        parkingLot->addSpots(VehicleType::BIKE, spot);
    }
    ParkingService *parkingService = new ParkingService(*parkingLot, *ticketService, *checkoutService);

    Vehicle *v1 = new Vehicle(1, VehicleType::CAR);
    Vehicle *v2 = new Vehicle(2, VehicleType::BIKE);
    Vehicle *v3 = new Vehicle(4, VehicleType::CAR);
    if (parkingService->parkVehicle(*v1)) {
        cout << "Vehicle has been parked at " << v1->getSpot()->getSpotId() << endl;
    } else {
        cout << "No parking spot available" << endl;
    }
    if (parkingService->parkVehicle(*v2)) {
        cout << "Vehicle has been parked at " << v2->getSpot()->getSpotId() << endl;
    } else {
        cout << "No parking spot available" << endl;
    }

    parkingService->removeVehicle(*v1);
    if (parkingService->parkVehicle(*v3)) {
        cout << "Vehicle has been parked at " << v3->getSpot()->getSpotId() << endl;
    } else {
        cout << "No parking spot available" << endl;
    }

}