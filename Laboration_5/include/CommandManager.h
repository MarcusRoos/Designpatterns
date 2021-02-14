//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_COMMANDMANAGER_H
#define DT063G_COMMANDMANAGER_H

#include "Command.h"
#include <memory>
#include <list>
/**
* Class Command Manager
 * This handles the commands sent back and forth the program, and keeps
 * track of which commands got used when, it stores everything in a
 * list and will always take the first command first, before proceeding
 * to the next one, this is especially critical when we're keeping track
 * of undo and redo.
*/
class CommandManager{
private:
    typedef std::list <std::unique_ptr<Command>> CommandList;
    CommandList undoList;
    CommandList redoList;
public:
    CommandManager() = default;
    ~CommandManager() = default;
    bool issueCommand(std::unique_ptr<Command> tmpCommand);
    bool undo();
    bool redo();
    std::unique_ptr<Command>executeUndo();
    std::unique_ptr<Command>executeRedo();
};

#endif //DT063G_COMMANDMANAGER_H
