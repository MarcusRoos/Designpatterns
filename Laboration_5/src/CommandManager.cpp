//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "CommandManager.h"
#include <iostream>


std::unique_ptr<Command> CommandManager::executeUndo()
{
    std::unique_ptr<Command> tmpCommand;
    tmpCommand = std::move(undoList.back());
    undoList.pop_back();
    return tmpCommand;
}

std::unique_ptr<Command> CommandManager::executeRedo()
{
    std::unique_ptr<Command> tmpCommand;
    tmpCommand = std::move(redoList.back());
    redoList.pop_back();
    return tmpCommand;
}

bool CommandManager::issueCommand(std::unique_ptr<Command> tmpCommand)
{
    if (tmpCommand->execute() && tmpCommand->isUndoable())
    {
        undoList.push_back(std::move(tmpCommand));
        return true;
    }
    return false;
}

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