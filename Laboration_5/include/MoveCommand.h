//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_MOVECOMMAND_H
#define DT063G_MOVECOMMAND_H

#include <fstream>
#include "Command.h"
#include "HanoiEngine.h"
#include <string>

/**
* The Move Command class
* Implements the functions from Command.h as well as its own constructors,
 * to its help it keeps track of which tower a disc was moved from, and to
 * which, it loads the hanoi engine to be able to use the functions
 * contained within that class. It has a bool log which is used when
 * we're reading from an already existing file.
*/

class MoveCommand : public Command
{
private:
    HanoiEngine &engine;
    int fromTower{}, toTower{};
    bool log = true;

public:
    MoveCommand(HanoiEngine &engine, int aFrom, int aTo);
    MoveCommand(HanoiEngine &engine, bool aLog);
    ~MoveCommand() override = default;
    bool execute() override;
    bool unExecute() override;
    bool isUndoable() override;
    void readFromStream(std::ifstream &) override;
};






#endif //DT063G_MOVECOMMAND_H
