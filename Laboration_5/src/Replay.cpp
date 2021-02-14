//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Replay.h"

/**
 * Function readLog, reads the log once open and loads the strings within
 * the log into the command string, which is then sent to replay last game.
 * **/
void Replay::readlog()
{
    string cmd;
    ifstream inFile("Hanoi.log");
    if (inFile.is_open())
    {
        inFile.get();
        while (inFile >> cmd)
        {
            replayLastGame(cmd, inFile);
        }
        replayLastGame("show", inFile);
        inFile.close();
    }

    else
        std::cout << "Unable to open file";
}

/**
 * Function replayLastGame, will replay the previous game loaded in Hanoi.log,
 * this checks whether the command is either "move" or "show" to be able to
 * accurate gauge the previous games. Will replay the entire game from start
 * to finish.
 * **/
void Replay::replayLastGame(const string& cmd, ifstream &inFile) {
    std::unique_ptr<Command> cmdPtr = nullptr;
    if (cmd == "move") {
        cmdPtr = std::unique_ptr<MoveCommand> (
                new MoveCommand(engine, false));
        cmdPtr->readFromStream(inFile);
        cmdPtr->execute();
    }

    else if (cmd == "show") {
        cmdPtr = std::unique_ptr<ShowCommand> (
                new ShowCommand(engine, false));
        cmdPtr->execute();
    }
}
