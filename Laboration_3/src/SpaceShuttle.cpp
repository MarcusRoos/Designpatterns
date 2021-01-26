//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "SpaceShuttle.h"

// Constructor, assigns vehicle type and
// adds the different power sources to the vehicle as well as a default source
SpaceShuttle::SpaceShuttle() : Vehicle("Space Shuttle", std::unique_ptr<PowerSource>(new FuelCellAD())) {
    powerSource.emplace_back(new V8ClassicAD());
    powerSource.emplace_back(new GasTurbineAD());
    powerSource.emplace_back(new FuelCellAD());
}

// Takes the vehicle for a test drive, tries to change engine mid-drive
void SpaceShuttle::drive() {
    incPower(40);
    tryStart();
    incPower(60);
    steerLeft(95);
    steerRight(312);
    decPower(30);
    std::string tmpEngine = poweredBy();
    setPowerSource(move(powerSource[0]));
    std::cout
            << "Changing from  " << tmpEngine << " to " << poweredBy() << std::endl;
    incPower(60);
    steerLeft(56);
    steerRight(40);
    steerLeft(80);
    steerRight(70);
    steerRight(320);
    steerLeft(45);
    decPower(30);
    stop();
}

// Steers the vehicle left by *param* degrees by printing as a string
void SpaceShuttle::steerLeft(int degrees)
{
    std::cout << "Steering left at " + std::to_string(degrees) + " degrees" << std::endl;
}

// Steers the vehicle right by *param* degrees by printing as a string
void SpaceShuttle::steerRight(int degrees)
{
    std::cout << "Steering right at " + std::to_string(degrees) + " degrees" << std::endl;
}
