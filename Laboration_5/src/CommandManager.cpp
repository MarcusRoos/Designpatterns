//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "CommandManager.h"
#include <iostream>

/**
 * Function executeUndo, returns a unique pointer of type Command.
 * It creates a unique pointer of type Command, moves the command in the back
 * of the undoList into the pointer, deletes this command from the list and
 * returns the pointer.
 * **/
std::unique_ptr<Command> CommandManager::executeUndo()
{
    std::unique_ptr<Command> tmpCommand;
    tmpCommand = std::move(undoList.back());
    undoList.pop_back();
    return tmpCommand;
}

/**
 * Function executeRedo, returns a unique pointer of type Command.
 * It creates a unique pointer of type Command, moves the command in the back
 * of the redoList into the pointer, deletes this command from the list and
 * returns the pointer.
 * **/
std::unique_ptr<Command> CommandManager::executeRedo()
{
    std::unique_ptr<Command> tmpCommand;
    tmpCommand = std::move(redoList.back());
    redoList.pop_back();
    return tmpCommand;
}

/**
 * Function issueCommand, will push the command into the list. It accepts
 * a unique pointer of type Command as parameter and returns a bool,
 * it will return true if a command was successfully pushed into the
 * undoList, otherwise it will return false.
 * **/
bool CommandManager::issueCommand(std::unique_ptr<Command> tmpCommand)
{
    if (tmpCommand->execute() && tmpCommand->isUndoable())
    {
        undoList.push_back(std::move(tmpCommand));
        return true;
    }
    return false;
}

/**
 * Function undo, returns a bool depending if it successfully undid a move,
 * if it failed to undo a move it will return false. This function will
 * check whether the undolist is empty or not, if it isn't empty, it will
 * try to reverse the previous move, effectively undoing it.
 * **/
bool CommandManager::undo()
{
    if (!undoList.empty())
    {
        std::unique_ptr<Command> tmpCommand = executeUndo();
        if (tmpCommand->unExecute()) {
            undoList.push_back(std::move(tmpCommand));
        }
        else {
            tmpCommand = nullptr;
            undo();
        }
        return true;
    }
    return false;
}

/**
 * Function redo, returns a bool depending if it successfully redid a move,
 * if it failed to redo a move it will return false. This function will
 * check whether the redolist is empty or not, if it isn't empty, it will
 * try to reverse the previous move, effectively redoing it.
 * **/
bool CommandManager::redo()
{
    if (!redoList.empty())
    {
        std::unique_ptr<Command> tmpCommand = executeRedo();
        if (tmpCommand->execute()) {
            redoList.push_back(std::move(tmpCommand));
        }
        else {
            redo();
        }
        return true;
    }
    return false;
}