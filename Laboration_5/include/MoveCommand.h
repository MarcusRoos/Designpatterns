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



class CommandMove : public Command
{
private:
    HanoiEngine &engine;
    int fromTower{}, toTower{};
    bool log = true;

public:
    CommandMove(HanoiEngine &engine, int aFrom, int aTo);
    CommandMove(HanoiEngine &engine, bool aLog);
    ~CommandMove() override = default;
    bool execute() override;
    bool unExecute() override;
    bool isUndoable() override;
    void readFromStream(std::ifstream &) override;
};






#endif //DT063G_MOVECOMMAND_H
