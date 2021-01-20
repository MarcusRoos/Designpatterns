//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_KLADDKAKA_H
#define DT063G_KLADDKAKA_H

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

class Kladdkaka : public BakingRecepy
{
    public:
    Kladdkaka() {
        neededIng.emplace_back("egg");
        neededIng.emplace_back("sugar");
        neededIng.emplace_back("baking-powder");
        neededIng.emplace_back("wheat-flour");
        neededIng.emplace_back("salt");
        neededIng.emplace_back("marge");
        neededIng.emplace_back("cocoa-powder");
    }

    ~Kladdkaka() override = default;
    void bakeIt() override {
        std::cout << "Baking Kladdkaka: ";
        for (const auto& ingExists : neededIng){
            std::cout << ingExists.getName() << ", ";
        }
        std::cout << std::endl;
    }
};

#endif //DT063G_KLADDKAKA_H
