//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_REPLAY_H
#define DT063G_REPLAY_H

#include <fstream>
#include "HanoiEngine.h"
#include "CommandManager.h"
#include "Command.h"
#include "MoveCommand.h"
#include "ShowCommand.h"
#include "ResetCommand.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Replay
{
private:
    HanoiEngine &engine;
public:
    /**
Constructor, adds hanoiengine

@param HanoiEngine
@return None
*/
    explicit Replay(HanoiEngine &tmpEngine) : engine(tmpEngine) {}
    /**
Default destructor

@param None
@return None
*/
    ~Replay() = default;
    /**
Reads the replay log

@param None
@return None
*/
    void readlog();
    /**
Replays the last game

@param string, ifstream
@return None
*/
    void replayLastGame(const string& cmd, ifstream &tmpLog);
};


#endif //DT063G_REPLAY_H
