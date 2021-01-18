//
// Created by Marcus Roos on 2021-01-18.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Management.h"
#include <iostream>

void pauseFunction(){
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
    std::cout << "Press any key to continue... ";
    std::cin.get();
}