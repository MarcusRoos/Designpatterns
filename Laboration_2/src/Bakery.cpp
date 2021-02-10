//
// Created by Marcus Roos on 2021-01-20.
// Mittuniversitet
// StudentID: Maro1904
//

#include <Bakery.h>
#include <Recipes.h>

/* Constructor, runs the bakery, creates an instance of BakingRecepy
 and retrieves the next recipe in line, if the ingredients exist it will
 "bake it" effectively calling a cout print showcasing its possible to
 bake the recipe. Once done it will delete the recipe and get the next recipe
 keeps going until there are no more recipes, in which case our custom
 exception "NoBakingException" is thrown and caught. */

Bakery::Bakery(){
    const std::string fileName = "pantry.dat";
    bakingRecepyManager = BakingRecepyManager(fileName);
    // Adds the 4 recommended recipes
    addRecepy(new Pizza());
    addRecepy(new Scones());
    addRecepy(new Kladdkaka());
    addRecepy(new Sockerkaka());
}

void Bakery::runBakery() {
    try
    {
        BakingRecepy* recipes;
        recipes = bakingRecepyManager.getNextBakingRecipe();

        while (recipes)   {
            std::cout << "name: " << recipes->getName() << std::endl;
            recipes->bakeIt();
            delete recipes;
            recipes = bakingRecepyManager.getNextBakingRecipe();
        }
    }
    catch (const NoBakingException &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void Bakery::addRecepy(BakingRecepy *recipe) {
    bakingRecepyManager.addNewRecipe(recipe);
}

