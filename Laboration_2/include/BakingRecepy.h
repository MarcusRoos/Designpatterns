//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_BAKINGRECEPY_H
#define DT063G_BAKINGRECEPY_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include "Ingredient.hpp"

class BakingRecepy {
private:
    std::string name;
protected:
    std::vector<Ingredient> neededIng;
    explicit BakingRecepy(std::string aName);
public:
    BakingRecepy() = default;
    virtual ~BakingRecepy() = default;
    std::string getName(){return name;}
    bool isBakeable(std::vector<Ingredient> const& availableIng);
    virtual void bakeIt() = 0;
};

#endif //DT063G_BAKINGRECEPY_H
