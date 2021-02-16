//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_VEHICLE_H
#define DT063G_VEHICLE_H

#include <string>
#include <iostream>
#include "PowerSource.h"
#include <memory>
#include <utility>
#include "PowerSourceAdapters.h"

/** Vehicle class. This keeps track of which power source as well as
 * which vehicle is currently being used. It tries to start
 * the engine, tries to stop it, as well as takes care of how fast the
 * vehicle is going.
 * */
class Vehicle
{
private:
    std::shared_ptr<PowerSource> powerSource;
    std::string vehicleType;
protected:
    Vehicle() = default;
    Vehicle(string avehicleType, std::shared_ptr<PowerSource> pwrSrc);
    bool tryStart();
    bool stop();
    bool incPower(int p = 5);
    bool decPower(int p = 5);
    static void steerLeft(int degrees);
    static void steerRight(int degrees);
public:
    /**
Default destructor of class Vehicle

@param None
@return None
*/
    ~Vehicle() = default;
    /**
Prints what type of vehicle is currently being driven

@param None
@return String
*/
    std::string toString();
    /**
Prints what type of engine the current vehicle is currently using

@param None
@return String
*/
    std::string poweredBy();
    /**
Pure virtual function drive, will be implement in the classes using
     the vehicle class

@param None
@return String
*/
    virtual void drive() = 0;
    /**
Sets the power source of the current vehicle.

@param unique pointer of type PowerSource
@return None
*/
    void setPowerSource(std::unique_ptr<PowerSource> powersource);
};

#endif //DT063G_VEHICLE_H
