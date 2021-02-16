//
// Created by Marcus Roos on 2021-02-16.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_HELPER_H
#define DT063G_HELPER_H

#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <iostream>
#include "PowerSourceAdapters.h"
#include "Vehicle.h"
#include "Car.h"
#include "Submarine.h"
#include "SpaceShuttle.h"

/** Helper header for the program, this will print all the menus
 * and call the main program to remove verbosity from the main function
 * */

/**
Prints the vehicle menu for the user to see and determine which vehicle
 they'd like to use. Returns an integer once done, contains input
 verification as well.

@param None
@return Integer
*/
int printVehicleMenu();

/**
Prints the engine menu for the user to see and determine which engine
 they'd like to use for their vehicle. Returns an integer once done,
 contains input verification as well.

@param None
@return Integer
*/
int printEngineMenu();

/**
Prints the retry menu for the user to decide whether they'd like to continue
 the program or not. Returns an integer once done, contains input
 verification as well.

@param None
@return Integer
*/
int printRetry();

/**
Calls the main program

@param None
@return None
*/
void mainProgram();


#endif //DT063G_HELPER_H
