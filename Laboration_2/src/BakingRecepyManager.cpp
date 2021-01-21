//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include <iostream>
#include <string>
#include "BakingRecepyManager.h"
#include "NoBakingException.h"

BakingRecepyManager::BakingRecepyManager(const std::string& fileName) {
    std::string ingredient;
    std::ifstream inFile("../../_Resources/" + fileName);
    if (inFile.is_open())
    {
        if (inFile.eof()) {
            std::cout << "Couldn't find any recipes" << std::endl;
        }
        else {
            while (getline(inFile, ingredient)) {
                availableIngredients.emplace_back(ingredient);
            }
            inFile.close();
        }
    }
    else {
        std::cout << "Could not locate " << fileName << std::endl;
    }

}

BakingRecepyManager::~BakingRecepyManager() {
    for(auto recipe : bakingRecipes) {
        delete recipe;
    }
}

BakingRecepy* BakingRecepyManager::getNextBakingRecipe() {
    NoBakingException noBakingException;
    if(hasAnotherRecepy()) {
        BakingRecepy *recipe = bakingRecipes[bakingRecipes.size()-1];
        bakingRecipes.pop_back();
        return recipe;
    }
    else {
        throw noBakingException; // NOLINT(misc-throw-by-value-catch-by-reference)
    }

}

bool BakingRecepyManager::hasAnotherRecepy() {
    return !bakingRecipes.empty();
}
