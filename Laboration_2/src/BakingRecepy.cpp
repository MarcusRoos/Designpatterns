//
// Created by Marcus Roos on 2021-01-20.
// Mittuniversitet
// StudentID: Maro1904
//
#include "BakingRecepy.h"

/* Checks whether the recipe is able to be produced or not, if all the
 required ingredients exists, its bakeable, otherwise its not.
 If it fails to find just one ingredient it will return false and
the recipe cannot be made */
bool BakingRecepy::isBakeable(std::vector<Ingredient> const &availableIng) {
    for (const auto& ingExists : neededIng)
    {
        if (std::find(availableIng.begin(), availableIng.end(),
                      ingExists) == availableIng.end()){
            std::cout << "Couldn't bake " <<
            getName() << " because we are missing "
            << ingExists.getName() << std::endl << std::endl;
            return false;
        }
    }
    return true;
}

BakingRecepy::BakingRecepy(std::string aName) {
    name = std::move(aName);
}


