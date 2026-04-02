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

using namespace std;

int main() {
    PaymentStrategy *strategy = new HourlyPaymentStrategy();
    PaymentProcessor *processor = new CardPayment();
    vector<ParkingSpot*> carSpots;
    vector<ParkingSpot*> bikeSpots;
    string idCar = "car";
    string idBike = "bike";

    for (int i=0; i<5; i++) {
        string newId = idCar + std::to_string(i);
        ParkingSpot *spot = new ParkingSpot(newId, SpotType::LARGE);
        carSpots.push_back(spot);
    }
    for (int i=0; i<5; i++) {
        string newId = idBike + std::to_string(i);
        ParkingSpot *spot = new ParkingSpot(newId, SpotType::SMALL);
        bikeSpots.push_back(spot);
    }
    ParkingLot *parkingLot = new ParkingLot(*strategy, *processor, carSpots, bikeSpots);

    Vehicle *v1 = new Vehicle(1, VehicleType::CAR);
    Vehicle *v2 = new Vehicle(2, VehicleType::BIKE);
    Vehicle *v3 = new Vehicle(4, VehicleType::CAR);
    parkingLot->parkVehicle(*v1);
    parkingLot->parkVehicle(*v2);

    parkingLot->removeVehicle(*v1);
    parkingLot->parkVehicle(*v3);

}