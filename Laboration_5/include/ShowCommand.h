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
    explicit ShowCommand(HanoiEngine &aEngine, bool aLog=true);
    ~ShowCommand() override = default;
    bool execute() override;
    bool unExecute() override;
    bool isUndoable() override;
    void readFromStream(std::ifstream &) override;
};

#endif //DT063G_SHOWCOMMAND_H
