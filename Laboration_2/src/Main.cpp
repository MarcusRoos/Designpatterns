//------------------------------------------------------------------------------
// Lab2.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "memstat.hpp"
#include "Bakery.h"
#include "Management.h"


int main()
{
    //Initializes bakery, sends filename to pantry as parameter
    const std::string fileName = "pantry.dat";
    Bakery bakery(fileName);

    //  Runs the bakery
    bakery.runBakery();
    pauseFunction();
    return 0;
}

