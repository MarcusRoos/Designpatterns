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
    /**
MoveCommand constructor, adds the engine as well as from and to integers

@param HanoiEngine, int, int
@return None
*/
    MoveCommand(HanoiEngine &engine, int aFrom, int aTo);
    /**
MoveCommand constructor, adds the engine, as well as a bool to check if the log
     exists or not

@param HanoiEngine, bool
@return None
*/
    MoveCommand(HanoiEngine &engine, bool aLog);
    /**
MoveCommand destructor

@param None
@return None
*/
    ~MoveCommand() override = default;
    /**
Implements the execute function from Command.h to move a disc from a tower

@param None
@return bool
*/
    bool execute() override;
    /**
Implements the unExecute function from Command.h to move a disc from a tower

@param None
@return bool
*/
    bool unExecute() override;
    /**
Everything the move command does is undoable

@param None
@return bool (true, always)
*/
    bool isUndoable() override;
    /**
Reads from the input stream

@param ifstream
@return None
*/
    void readFromStream(std::ifstream &) override;
};






#endif //DT063G_MOVECOMMAND_H
