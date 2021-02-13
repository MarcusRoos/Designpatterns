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
