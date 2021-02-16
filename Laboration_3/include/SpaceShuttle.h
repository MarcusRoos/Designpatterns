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

class SpaceShuttle : public Vehicle
{

public:
    SpaceShuttle(std::shared_ptr<PowerSource> pwrSrc);
    ~SpaceShuttle();
    void drive() override;
    static void steerLeft(int degrees);
    static void steerRight(int degrees);
};






#endif //DT063G_SPACESHUTTLE_H
