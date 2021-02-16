//
// Created by Marcus Roos on 2021-02-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_HELPER_H
#define DT063G_HELPER_H
#include <iostream>
#include "MainComponent.h"
#include "ConcreteComponents.h"
#include "ConcreteDecorators.h"
#include <limits>
#include <memory>
#include <string>
#include <iomanip>

/** Helper header for the program, this will print all the menus
 * and call the main program to remove verbosity from the main function
 * */
void mainProgram();

/**
Prints the drink menu for the user to see and determine which drink
 they'd like to have. Returns an integer once done, contains input
 verification as well.

@param None
@return Integer
*/
int printDrinkMenu();

/**
Prints the decorator menu for the user to see and determine which extras
 they'd like to have for their drink. Returns an integer once done,
 contains input verification as well.

@param None
@return Integer
*/
int printDecoratorMenu();

#endif //DT063G_HELPER_H
