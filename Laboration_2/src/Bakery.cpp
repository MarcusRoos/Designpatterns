//
// Created by Marcus Roos on 2021-01-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include <Bakery.h>

/* Constructor, runs the bakery, creates an instance of BakingRecepy
 and retrieves the next recipe in line, if the ingredients exist it will
 "bake it" effectively calling a cout print showcasing its possible to
 bake the recipe. Once done it will delete the recipe and get the next recipe
 keeps going until there are no more recipes, in which case our custom
 exception "NoBakingException" is thrown and caught. */
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

