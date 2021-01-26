//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Car.h"

// Constructor, assigns vehicle type and
// adds the different power sources to the vehicle as well as a default source
Car::Car() : Vehicle("Car", std::unique_ptr<PowerSource>(new V8ClassicAD())) {
    powerSource.emplace_back(new V8ClassicAD());
    powerSource.emplace_back(new GasTurbineAD());
    powerSource.emplace_back(new FuelCellAD());
}

// Takes the vehicle for a test drive, tries to change engine mid-drive
void Car::drive() {
    incPower(40);
    tryStart();
    incPower(75);
    steerRight(50);
    steerLeft(90);
    decPower(45);
    std::string tmpEngine = poweredBy();
    setPowerSource(move(powerSource[1]));
    std::cout
            << "Changing from  " << tmpEngine << " to " << poweredBy() << std::endl;
    incPower(75);
    steerRight(45);
    steerLeft(65);
    steerRight(70);
    steerLeft(95);
    steerLeft(80);
    steerRight(120);
    decPower(45);
    stop();
}

// Steers the vehicle left by *param* degrees by printing as a string
void Car::steerLeft(int degrees) {
    std::cout << "Steering left at " + std::to_string(degrees) + " degrees" << std::endl;
}

// Steers the vehicle right by *param* degrees by printing as a string
void Car::steerRight(int degrees) {
    std::cout << "Steering right at " + std::to_string(degrees) + " degrees" << std::endl;
}