//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ShowCommand.h"

ShowCommand::ShowCommand(HanoiEngine &aEngine, bool aLog) : engine(aEngine) {
    hanoiLog = aLog;
}

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
    }
    return false;
}
bool ShowCommand::unExecute(){
    return false;
}
bool ShowCommand::isUndoable(){
    return true;
}
void ShowCommand::readFromStream(std::ifstream &){

}


