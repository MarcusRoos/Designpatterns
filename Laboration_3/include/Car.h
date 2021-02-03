//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_CAR_H
#define DT063G_CAR_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "Vehicle.h"


class Car : public Vehicle
{

public:
    Car();
    ~Car();
    void drive() override;
    static void steerLeft(int degrees);
    static void steerRight(int degrees);
};


#endif //DT063G_CAR_H
