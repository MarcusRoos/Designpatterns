//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Vehicle.h"
#include <utility>

// Constructor, accepts string and unique pointer as parameters
Vehicle::Vehicle(string avehicleType, std::unique_ptr <PowerSource> aPowerSource) {
    vehicleType = std::move(avehicleType);
    powerSource = std::move(powerSource);
}

// Wanted steerLeft and steerRight to be pure virtual but to conform with requirements
// I had to implement some kind of function here, hence why its empty.
void Vehicle::steerLeft(int degrees)  {

}

void Vehicle::steerRight(int degrees) {

}

// Increases power
bool Vehicle::incPower(int p) {
    return powerSource->incPower(p);
}

// Decreases power
bool Vehicle::decPower(int p) {
    return powerSource->decPower(p);
}

// Tries to start the vehicle
bool Vehicle::tryStart() {
    return powerSource->tryStart();
}

// Stops the vehicle
bool Vehicle::stop() {
    powerSource->stop();
    powerSource.reset();
    return true;
}

// Returns what the vehicle is powered by as a string
std::string Vehicle::poweredBy() {
    return powerSource->type();
}

// Returns vehicle type as a string
std::string Vehicle::toString() {
    return vehicleType;
}

void Vehicle::setPowerSource(std::unique_ptr<PowerSource> aPowerSource) {
    powerSource = std::move(aPowerSource);
}



// Sets the power source of the vehicle

