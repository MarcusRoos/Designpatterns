//
// Created by Marcus Roos on 2021-02-22.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_HELPER_H
#define DT063G_HELPER_H

#include "HanoiEngine.h"
#include "CommandManager.h"
#include "ShowCommand.h"
#include "ResetCommand.h"
#include "Replay.h"
#include "Management.h"
#include "MoveCommand.h"
#include <iostream>
#include <string>
#include "Helper.h"
#include <limits>

/** Helper header for the program, this will print all the menus
 * and call the main program to remove verbosity from the main function
 * */

/**
  Starts the main program

  @param None
  @return None
*/
void printMainProgram();
/**
  Prints the main menu and returns user input as int

  @param None
  @return int
*/
int printMainMenu();
/**
  Prints the replay menu and returns user input as int

  @param None
  @return int
*/
int printReplayMenu();
/**
  Prints the reset menu, resets the game and reloads the game to user defined
  amount of discs

  @param None
  @return int
*/
int reset();

#endif //DT063G_HELPER_H
