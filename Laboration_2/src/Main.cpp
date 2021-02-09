//------------------------------------------------------------------------------
// Lab2.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "memstat.hpp"
#include "Bakery.h"
#include "Management.h"


int main()
{
    //Initializes bakery, sends filename to pantry as parameter
    Bakery bakery;

    //  Runs the bakery
    bakery.runBakery();
    // Pauses the program to gauge whats happening
    pauseFunction();
    return 0;
}

