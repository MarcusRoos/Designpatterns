//
// Created by Marcus Roos on 2021-01-20.
// Mittuniversitet
// StudentID: Maro1904
//
#include "BakingRecepy.h"

bool BakingRecepy::isBakeable(std::vector<Ingredient> const &availableIng) {
    for (const auto& ingExists : neededIng)
    {
        if (std::find(availableIng.begin(), availableIng.end(),
                      ingExists) == availableIng.end()){
            return false;
        }
    }
    return true;
}

BakingRecepy::BakingRecepy(std::string aName) {
    name = std::move(aName);
}


