//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_SPACESHUTTLE_H
#define DT063G_SPACESHUTTLE_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "Vehicle.h"

/** SpaceShuttle class, extends public interface Vehicle.
 * Will implement the virtual functions from the class Vehicle as well
 * as implement a driving scenario*/

class SpaceShuttle : public Vehicle
{

public:
    /**
Explicit constructor for class SpaceShuttle, requires a shared pointer of type
 PowerSource to initialize the class Vehicle.

@param Shared ptr of type PowerSource
@return None
*/
    explicit SpaceShuttle(std::shared_ptr<PowerSource> pwrSrc);
    /**
Default destructor for class SpaceShuttle

@param None
@return None
*/
    ~SpaceShuttle() = default;
    /**
Implement the drive function from the class Vehicle,
 will create a drive scenario with this vehicle as well as
 provided power source by the constructor

@param None
@return None
*/
    void drive() override;
    /**
Implements the steerLeft function from the vehicle class, will steer in
     left in the degree provided by parameter

@param Integer
@return None
*/
    static void steerLeft(int degrees);
    /**
Implements the steerRight function from the vehicle class, will steer in
 right in the degree provided by parameter

@param Integer
@return None
*/
    static void steerRight(int degrees);
};






#endif //DT063G_SPACESHUTTLE_H
