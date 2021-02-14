//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ShowCommand.h"
/**
 * MoveCommand constructor, requires hanoiengine and a bool as parameter.
 * **/
ShowCommand::ShowCommand(HanoiEngine &aEngine, bool aLog) : engine(aEngine) {
    hanoiLog = aLog;
}

/**
 * Function execute, will call the show function within hanoi engine, as well
 * as write to Hanoi.log, returns false if the show function can't be called,
 * and returns true if it can.
 * **/
bool ShowCommand::execute(){
    engine.show();
    if (hanoiLog)
    {
        std::ofstream logfile;
        logfile.open("Hanoi.log", std::fstream::app);
        if (!logfile.is_open())
        {
            cout << "Couldn't find Hanoi.log";
        }
        else {
            logfile << "show \n";
            logfile.close();
        }
        return true;
    }
    return false;
}

/**
 * States that the show command cant be unexecuted.
 * **/
bool ShowCommand::unExecute(){
    return false;
}

/**
 * States that the show command cant be undoable.
 * **/
bool ShowCommand::isUndoable(){
    return true;
}

void ShowCommand::readFromStream(std::ifstream &){

}


