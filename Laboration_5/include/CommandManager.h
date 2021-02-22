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
class CommandManager
{
private:
    typedef std::list<std::unique_ptr<Command>> CommandList;
    CommandList iUndoList;
    CommandList iRedoList;
    /**
  Calls the executeUndo function to execute the next undo task

  @param None
  @return unique pointer of type Command
*/
    std::unique_ptr<Command> executeUndo();
    /**
Calls the executeRedo function to execute the next redo task

@param None
@return unique pointer of type Command
*/
    std::unique_ptr<Command> executeRedo();
    /**
Adds an undo command to the undo command list

@param unique pointer of type Command
@return None
*/
    void addUndo(std::unique_ptr<Command> pCommand);
    /**
Adds a redo command to the redo command list

@param unique pointer of type Command
@return None
*/
    void addRedo(std::unique_ptr<Command> pCommand);
public:
    /**
Default constructor

@param None
@return None
*/
    CommandManager();
    /**
Default destructor

@param None
@return None
*/
    ~CommandManager();
    /**
Issues the next command in the command list

@param unique pointer of type Command
@return None
*/
    bool issueCommand(std::unique_ptr<Command> pCommand);
    /**
Checks whether the undo list is empty or not, if its not, it will call the
     command to undo the previous move, and add it to the redolist so it
     can later redo the move it just undid.

@param unique pointer of type Command
@return bool
*/
    bool undo();
    /**
Checks whether the redo list is empty or not, if its not, it will call the
 command to redo the previous move, and add it to the undolist so it
 can later undo the move it just redid.

@param unique pointer of type Command
@return bool
*/
    bool redo();
};

#endif //DT063G_COMMANDMANAGER_H
