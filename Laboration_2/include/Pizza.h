//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_PIZZA_H
#define DT063G_PIZZA_H

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

class Pizza : public BakingRecepy
{

public:
    Pizza()
    {
        neededIng.emplace_back("oil");
        neededIng.emplace_back("yeast");
        neededIng.emplace_back("wheat-flour");
        neededIng.emplace_back("salt");
    }

    ~Pizza() override = default;
    void bakeIt() override {
        std::cout << "Baking Pizza: ";
        for (const auto& ingExists : neededIng){
            std::cout << ingExists.getName() << ", ";
        }
        std::cout << std::endl;
    }

};

#endif //DT063G_PIZZA_H
