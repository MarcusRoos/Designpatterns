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


class Vehicle
{
private:
    std::unique_ptr<PowerSource> powerSource;
    std::string vehicleType;
protected:
    Vehicle() = default;
    Vehicle(string avehicleType, std::unique_ptr<PowerSource> aPowerSource);

    bool tryStart();
    bool stop();
    bool incPower(int p = 5);
    bool decPower(int p = 5);

    static void steerLeft(int degrees);
    static void steerRight(int degrees);
public:
    ~Vehicle() = default;

    std::string toString();
    std::string poweredBy();

    virtual void drive() = 0;
    void setPowerSource(std::unique_ptr<PowerSource> ptr);
};

#endif //DT063G_VEHICLE_H
