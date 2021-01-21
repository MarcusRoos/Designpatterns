//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include <iostream>
#include <string>
#include "BakingRecepyManager.h"
#include "NoBakingException.h"

// Constructor, gets name of file passed down as parameter, uses
// filename to locate file and read, will read until end of file and
// push back every value into availableIngredients vector.
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

// Deconstructor to ensure no memory leaks
BakingRecepyManager::~BakingRecepyManager() {
    for(auto recipe : bakingRecipes) {
        delete recipe;
    }
}

// Gets next baking recipe, will search through the bakingRecipes vector
// to find any more baking recipes, if found it deletes that entry in the
// vector and returns the found recipe. Looks until hasAnotherRecepy returns
// false, in which case there are no more recipes.
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

// Returns whether bakingRecipes vector is empty or not
bool BakingRecepyManager::hasAnotherRecepy() {
    return !bakingRecipes.empty();
}
