//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Submarine.h"

// Constructor, assigns vehicle type and
// adds the different power sources to the vehicle as well as a default source
Submarine::Submarine() : Vehicle("Submarine", std::unique_ptr<PowerSource>(new FuelCellAD())){
    powerSource.emplace_back(new V8ClassicAD());
    powerSource.emplace_back(new GasTurbineAD());
    powerSource.emplace_back(new FuelCellAD());
}

// Takes the vehicle for a test drive, tries to change engine mid-drive
void Submarine::drive(){
    incPower(40);
    tryStart();
    incPower(50);
    steerLeft(350);
    steerRight(355);
    decPower(20);
    std::string tmpEngine = poweredBy();
    setPowerSource(move(powerSource[2]));
    std::cout
            << "Changing from  " << tmpEngine << " to " << poweredBy() << std::endl;
    incPower(50);
    steerLeft(280);
    steerRight(290);
    steerLeft(70);
    steerLeft(120);
    steerRight(200);
    decPower(20);
    stop();
}

// Steers the vehicle left by *param* degrees by printing as a string
void Submarine::steerLeft(int degrees)
{
    std::cout << "Steering left at " + std::to_string(degrees) + " degrees" << std::endl;
}

// Steers the vehicle right by *param* degrees by printing as a string
void Submarine::steerRight(int degrees)
{
    std::cout << "Steering right at " + std::to_string(degrees) + " degrees" << std::endl;
}