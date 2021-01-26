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
private:
    std::vector<std::unique_ptr<PowerSource>> engines;
public:
    Car();
    ~Car() = default;
    void drive() override;
    static void steerLeft(int degrees);
    static void steerRight(int degrees);

};


#endif //DT063G_CAR_H
