//
// Created by Marcus Roos on 2021-01-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_BAKINGRECEPYMANAGER_H
#define DT063G_BAKINGRECEPYMANAGER_H

#include <string>
#include <iostream>
#include <fstream>

#include "Ingredient.hpp"
#include "BakingRecepy.h"

class BakingRecepyManager {

private:
    std::vector<BakingRecepy*> bakingRecipes;
    std::vector<Ingredient> availableIngredients;
public:
    BakingRecepyManager() = default;
    ~BakingRecepyManager();
    explicit BakingRecepyManager(const std::string& fileName);
    bool hasAnotherRecepy();
    void addNewRecipe(BakingRecepy *recipe) {bakingRecipes.push_back(recipe);}
    std::vector<Ingredient> getIngredient() {return availableIngredients;}
    BakingRecepy* getNextBakingRecipe();
};

#endif //DT063G_BAKINGRECEPYMANAGER_H
