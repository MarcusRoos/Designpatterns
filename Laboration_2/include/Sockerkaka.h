//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_SOCKERKAKA_H
#define DT063G_SOCKERKAKA_H

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

class Sockerkaka : public BakingRecepy
{

public:
    Sockerkaka()
    {
        neededIng.emplace_back("egg");
        neededIng.emplace_back("sugar");
        neededIng.emplace_back("baking-powder");
        neededIng.emplace_back("wheat-flour");
        neededIng.emplace_back("marge");
        neededIng.emplace_back("lemon");
    }
    ~Sockerkaka() override = default;
    void bakeIt() override {
        std::cout << "Baking Sockerkaka: ";
        for (const auto& ingExists : neededIng){
            std::cout << ingExists.getName() << ", ";
        }
        std::cout << std::endl;
    }
};

#endif //DT063G_SOCKERKAKA_H
