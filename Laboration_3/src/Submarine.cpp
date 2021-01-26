//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Submarine.h"

Submarine::Submarine() : Vehicle("Submarine", std::unique_ptr<PowerSource>(new FuelCellAD())){
    powerSource.emplace_back(new V8ClassicAD());
    powerSource.emplace_back(new GasTurbineAD());
    powerSource.emplace_back(new FuelCellAD());
}

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
void Submarine::steerLeft(int degrees)
{
    std::cout << "Steering left at " + std::to_string(degrees) + " degrees" << std::endl;
}
void Submarine::steerRight(int degrees)
{
    std::cout << "Steering right at " + std::to_string(degrees) + " degrees" << std::endl;
}