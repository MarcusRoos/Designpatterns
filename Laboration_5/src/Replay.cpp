//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Replay.h"

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

void Replay::replayLastGame(const string& cmd, ifstream &inFile) {
    std::unique_ptr<Command> cmdPtr = nullptr;
    if (cmd == "move") {
        cmdPtr = std::unique_ptr<CommandMove> (
                new CommandMove(engine, false));
        cmdPtr->readFromStream(inFile);
        cmdPtr->execute();
    }

    else if (cmd == "show") {
        cmdPtr = std::unique_ptr<CommandShow> (
                new CommandShow(engine, false));
        cmdPtr->execute();
    }
}
