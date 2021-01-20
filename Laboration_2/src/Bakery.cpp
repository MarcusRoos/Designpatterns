//
// Created by Marcus Roos on 2021-01-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include <Bakery.h>

void Bakery::runBakery() {
    try
    {
        BakingRecepy *recipes;
        recipes = bakingRecepyManager.getNextBakingRecipe();
        while (recipes)   {
            if (recipes->isBakeable(bakingRecepyManager.getIngredient())) {
                recipes->bakeIt();
            }
            delete recipes;
            recipes = bakingRecepyManager.getNextBakingRecipe();
        }
    }
    catch (const NoBakingException &ex) {
        std::cout << ex.what() << std::endl;
    }
}

