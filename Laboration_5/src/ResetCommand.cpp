//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ResetCommand.h"

ResetCommand::ResetCommand(HanoiEngine &aEngine, int aDiscs) : engine(aEngine){
    discs = aDiscs;
}

bool ResetCommand::execute(){
    engine.reset(discs);
    return false;
}
bool ResetCommand::unExecute(){
    return false;
}
bool ResetCommand::isUndoable(){
    return false;
}
void ResetCommand::readFromStream(std::ifstream &) {

}
