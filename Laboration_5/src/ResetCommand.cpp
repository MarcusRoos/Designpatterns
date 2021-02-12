//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ResetCommand.h"

CommandReset::CommandReset(HanoiEngine &aEngine, int aDiscs) : engine(aEngine){
    discs = aDiscs;
}

bool CommandReset::execute(){
    engine.reset(discs);
    return false;
}
bool CommandReset::unExecute(){
    return false;
}
bool CommandReset::isUndoable(){
    return true;
}
void CommandReset::readFromStream(std::ifstream &) {
    // Need to implement empty function due to pure virtual
}
