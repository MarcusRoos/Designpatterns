//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_SHOWCOMMAND_H
#define DT063G_SHOWCOMMAND_H

#include "HanoiEngine.h"
#include "Command.h"
#include <fstream>

/**
* The Show Command class
* Implements the functions from Command.h as well as its own constructors,
 * to its help it keeps track of the amount of discs to reset the engine to.
 * It has a bool log which is used when
 * we're reading from an already existing file.
*/
class ShowCommand : public Command
{

private:
    HanoiEngine &engine;
    bool hanoiLog;
public:
    /**
Constructor, adds engine, and sets log to true

@param HanoiEngine, bool
@return None
*/
    explicit ShowCommand(HanoiEngine &aEngine, bool aLog=true);
    /**
Destructor

@param None
@return None
*/
    ~ShowCommand() override = default;
    /**
Implements the execute from Command

@param None
@return bool
*/
    bool execute() override;
    /**
Implements the unExecute from Command

@param None
@return bool
*/
    bool unExecute() override;
    /**
Implements the isUndoable from Command

@param None
@return bool (true)
*/
    bool isUndoable() override;
    /**
Reads from instream

@param ifstream
@return void
*/
    void readFromStream(std::ifstream &) override;
};

#endif //DT063G_SHOWCOMMAND_H
