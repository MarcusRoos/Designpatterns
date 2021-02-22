//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_RESETCOMMAND_H
#define DT063G_RESETCOMMAND_H

#include "HanoiEngine.h"
#include "Command.h"
#include <fstream>

/**
* The Reset Command class
* Implements the functions from Command.h as well as its own constructors,
 * to its help it keeps track of the amount of discs to reset the engine to.
*/
class ResetCommand : public Command
{

private:
    HanoiEngine &engine;
    int discs;
public:
    /**
Constructor, adds engine, and amount of discs

@param HanoiEngine, int
@return None
*/
    ResetCommand(HanoiEngine &aEngine, int aDiscs);
    /**
Default destructor

@param None
@return None
*/
    ~ResetCommand() override = default;
    /**
Implements the execute function from Command by resetting the towers

@param None
@return bool
*/
    bool execute() override;
    /**
This move cannot be unExecuted

@param None
@return None
*/
    bool unExecute() override;
    /**
This move isn't unDoable

@param None
@return bool (false)
*/
    bool isUndoable() override;
    /**
Reads from stream

@param ifstream
@return None
*/
    void readFromStream(std::ifstream &) override;
};


#endif //DT063G_RESETCOMMAND_H
