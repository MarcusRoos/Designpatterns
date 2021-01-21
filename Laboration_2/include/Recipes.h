//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_RECIPES_H
#define DT063G_RECIPES_H

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
        std::cout << std::endl << "Mash ingredients together, put topping on "
                                  "dough, keep in oven at "
                                  "225C for 10min." << std::endl << std::endl;
    }

};

class Scones : public BakingRecepy
{
public:
    Scones()
    {
        neededIng.emplace_back("oil");
        neededIng.emplace_back("baking-powder");
        neededIng.emplace_back("wheat-flour");
        neededIng.emplace_back("salt");
        neededIng.emplace_back("sugar");
        neededIng.emplace_back("milk");
    }
    ~Scones() override = default;
    void bakeIt() override {
        std::cout << "Baking Scones: ";
        for (const auto& ingExists : neededIng){
            std::cout << ingExists.getName() << ", ";
        }
        std::cout << std::endl << "Mash ingredients together, put dough in "
                                  "oven at 225C for 10min."
                << std::endl << std::endl;
    }
};
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
        std::cout << std::endl << "Mash ingredients together, put in oven "
                                  "at 225C for 15min. " << std::endl
                                  << std::endl;
    }
};

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
        std::cout << std::endl << "Mash ingredients together, "
                                  "keep in oven at 200C for 10min."
                << std::endl << std::endl;
    }
};

#endif //DT063G_RECIPES_H
