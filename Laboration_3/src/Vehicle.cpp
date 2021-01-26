//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Vehicle.h"
#include <utility>

Vehicle::Vehicle(string avehicleType, std::unique_ptr<PowerSource> aPowerSource) {
    vehicleType = std::move(avehicleType);
    powerSource = std::move(aPowerSource);
}

// Wanted steerLeft and steerRight to be pure virtual but to conform with requirements
// I had to implement some kind of function here, hence why its empty.
void Vehicle::steerLeft(int degrees)  {

}

void Vehicle::steerRight(int degrees) {

}

bool Vehicle::incPower(int p) {
    return powerSource->incPower(p);
}

bool Vehicle::decPower(int p) {
    return powerSource->decPower(p);
}

bool Vehicle::tryStart() {
    return powerSource->tryStart();
}

bool Vehicle::stop() {
    powerSource->stop();
    return true;
}

std::string Vehicle::poweredBy() {
    return powerSource->type();
}

std::string Vehicle::toString() {
    return vehicleType;
}

void Vehicle::setPowerSource(std::unique_ptr<PowerSource> ptr) {
        powerSource = std::move(ptr);
}
