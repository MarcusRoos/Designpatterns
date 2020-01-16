//------------------------------------------------------------------------------
// Lab2.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "Lab2.h"
#include <iostream>
#include <fstream>
#include "Ingredient.hpp"
#include "memstat.hpp"

int main() {
    std::cout << getAssignmentInfo() << std::endl;

    // Example use of working with resource files
    std::cout << std::endl << "====================" << std::endl
        << "CONTENTS OF PANTRY"
        << std::endl << "====================" << std::endl;

    std::ifstream infile("../../_Resources/pantry.dat");
    if (!infile.is_open())
        std::cout << "unable to open file" << std::endl;


    string line;
    while (getline(infile, line)) {
        // Ingredient is a class provided for solving the assignment and
        // you find it under ../_CodeBase/Bakery/
        std::cout << Ingredient(line) << std::endl;
    }

    infile.close();

    return 0;
}

