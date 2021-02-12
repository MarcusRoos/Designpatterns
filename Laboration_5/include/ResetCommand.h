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


class CommandReset : public Command
{

private:
    HanoiEngine &engine;
    int discs;
public:
    CommandReset(HanoiEngine &aEngine, int aDiscs);
    ~CommandReset() override = default;
    bool execute() override;
    bool unExecute() override;
    bool isUndoable() override;
    void readFromStream(std::ifstream &) override;
};


#endif //DT063G_RESETCOMMAND_H
