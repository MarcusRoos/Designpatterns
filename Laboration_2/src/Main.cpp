//------------------------------------------------------------------------------
// Lab2.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

//#include "memstat.hpp"
#include "Bakery.h"
#include "Recipes.h"
#include "Management.h"

int main()
{
    //Initializes bakery, sends filename to pantry as parameter
    const std::string fileName = "pantry.dat";
    Bakery bakery(fileName);

    // Adds the 4 recommended recipes
    bakery.addRecepy(new Recipes);
    bakery.addRecepy(new Scones);
    bakery.addRecepy(new Kladdkaka);
    bakery.addRecepy(new Sockerkaka);

    //  Runs the bakery
    bakery.runBakery();
    pauseFunction();
    return 0;
}

