//
// Created by Marcus Roos on 2021-01-26.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_SUBMARINE_H
#define DT063G_SUBMARINE_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include "Vehicle.h"


class Submarine : public Vehicle
{
private:
    std::vector<std::unique_ptr<PowerSource>> powerSource;
public:
    Submarine();
    ~Submarine() = default;
    void drive() override;
    static void steerLeft(int degrees);
    static void steerRight(int degrees);
};



#endif //DT063G_SUBMARINE_H
