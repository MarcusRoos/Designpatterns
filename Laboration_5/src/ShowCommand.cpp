//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ShowCommand.h"

CommandShow::CommandShow(HanoiEngine &aEngine, bool aLog) : engine(aEngine) {
    hanoiLog = aLog;
}

bool CommandShow::execute(){
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
bool CommandShow::unExecute(){
    return false;
}
bool CommandShow::isUndoable(){
    return true;
}
void CommandShow::readFromStream(std::ifstream &){

}


