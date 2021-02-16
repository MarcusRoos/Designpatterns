//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#include "SpaceShuttle.h"

// Constructor, assigns vehicle type and
// adds the different power sources to the vehicle as well as a default source
SpaceShuttle::SpaceShuttle(std::shared_ptr<PowerSource> pwrSrc) : Vehicle("SpaceShuttle", std::move(pwrSrc)) {

}

// Takes the vehicle for a test drive, tries to change engine mid-drive
void SpaceShuttle::drive() {
    incPower(40);
    tryStart();
    incPower(75);
    steerRight(50);
    steerLeft(90);
    decPower(45);
    setPowerSource( std::unique_ptr<V8ClassicAD>(new V8ClassicAD()));
    std::cout << "Changing power source to " << poweredBy() << std::endl;
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
void SpaceShuttle::steerLeft(int degrees)
{
    std::cout << "Steering left at " + std::to_string(degrees) + " degrees" << std::endl;
}

// Steers the vehicle right by *param* degrees by printing as a string
void SpaceShuttle::steerRight(int degrees)
{
    std::cout << "Steering right at " + std::to_string(degrees) + " degrees" << std::endl;
}
