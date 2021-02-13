//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "MoveCommand.h"

CommandMove::CommandMove(HanoiEngine &tmpEngine, int aFrom, int aTo) : engine(tmpEngine){
    fromTower = aFrom;
    toTower = aTo;
}

bool CommandMove::execute() {

    if (engine.move(fromTower, toTower)) {
        if (log) {
            std::ofstream logfile;
            logfile.open("Hanoi.log", std::fstream::app);
            if (logfile.is_open())
            {
                logfile << "move " << fromTower << ":" << toTower << "\n";
                logfile.close();
            }
            else
                cout << "Unable to open file";
        }
        return true;
    }
    return false;
}

bool CommandMove::unExecute() {
    engine.move(fromTower, toTower);
    return true;
}

bool CommandMove::isUndoable() {
    return true;
}

void CommandMove::readFromStream(std::ifstream &inFile) {
    std::string positions, movefrom, moveto;
    inFile >> positions;
    inFile.get();

    movefrom = positions.substr(0, positions.find(':'));
    moveto = positions.substr(positions.find(':') + 1, positions.length()-1);

    std::cout << "Move: " + movefrom + " to " + moveto << std::endl;

    toTower = stoi(moveto);
    fromTower = stoi(movefrom);

}

CommandMove::CommandMove(HanoiEngine &tmpEngine, bool aLog) : engine(tmpEngine) {
    log = aLog;
}