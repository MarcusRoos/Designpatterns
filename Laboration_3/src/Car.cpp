//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Car.h"

Car::Car() : Vehicle("Car", std::unique_ptr<PowerSource>(new V8ClassicAD())) {
    engines.emplace_back(new V8ClassicAD());
    engines.emplace_back(new GasTurbineAD());
    engines.emplace_back(new FuelCellAD());
}

void Car::drive() {
    incPower(40);
    tryStart();
    incPower(75);
    steerRight(50);
    steerLeft(90);
    decPower(45);
    std::string tmpEngine = poweredBy();
    setPowerSource(move(engines[1]));
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
void Car::steerLeft(int degrees) {
    std::cout << "Steering left at " + std::to_string(degrees) + " degrees" << std::endl;
}
void Car::steerRight(int degrees) {
    std::cout << "Steering right at " + std::to_string(degrees) + " degrees" << std::endl;
}