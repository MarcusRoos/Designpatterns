//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "MoveCommand.h"
/**
 * MoveCommand constructor, requires hanoiengine and two integers as parameters.
 * **/
MoveCommand::MoveCommand(HanoiEngine &tmpEngine, int aFrom, int aTo) : engine(tmpEngine){
    fromTower = aFrom;
    toTower = aTo;
}

/**
 * Secondary MoveCommand constructor, requires
 * hanoiengine and a bool as parameter, this is used to check whether a log
 * already exists or not, to be able to determine replaying.
 * **/
MoveCommand::MoveCommand(HanoiEngine &tmpEngine, bool aLog) : engine(tmpEngine) {
    log = aLog;
}

/**
 * Function execute, will call the move function within hanoi engine, as well
 * as write to Hanoi.log, returns false if the move function can't move any
 * pieces, and returns true if it can.
 * **/
bool MoveCommand::execute() {

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

/**
 * Calls the move function from the engine with the values loaded in toTower
 * and fromTower
 * **/
bool MoveCommand::unExecute() {
    if (engine.move(toTower, fromTower)){
    if (log) {
        std::ofstream logfile;
        logfile.open("Hanoi.log", std::fstream::app);
        if (logfile.is_open())
        {
            logfile << "move " << toTower << ":" << fromTower << "\n";
            logfile.close();
        }
        else
            cout << "Unable to open file";
    }
    return true;
}
return false;
}

/**
 * Checks whether the value is undoable or not.
 * **/
bool MoveCommand::isUndoable() {
    return true;
}

/**
 * Reads from the in stream once loaded, used to replay the previous game.
 * **/
void MoveCommand::readFromStream(std::ifstream &inFile) {
    std::string positions, movefrom, moveto;
    inFile >> positions;
    inFile.get();

    movefrom = positions.substr(0, positions.find(':'));
    moveto = positions.substr(positions.find(':') + 1, positions.length()-1);

    std::cout << "Move: " + movefrom + " to " + moveto << std::endl;

    toTower = stoi(moveto);
    fromTower = stoi(movefrom);

}
