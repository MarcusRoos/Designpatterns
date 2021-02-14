//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_COMMAND_H
#define DT063G_COMMAND_H
#include <fstream>
/**
* Virtual class Command
* All functions are pure virtual and each specific command will implement
 * their own solution.
*/
class Command {
public:
    virtual bool execute()=0; // Execute the command
    virtual bool unExecute()=0; // Undo the command
    virtual bool isUndoable()=0; // Undoable?
    virtual void readFromStream(std::ifstream&)=0; //Read from stream
    virtual~Command()= default;
};

#endif //DT063G_COMMAND_H
