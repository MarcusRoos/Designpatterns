//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#include "CommandManager.h"
#include <iostream>

CommandManager::CommandManager() = default;

CommandManager::~CommandManager()
{
    iUndoList.erase(iUndoList.begin(), iUndoList.end());
    iRedoList.erase(iRedoList.begin(), iRedoList.end());
}

std::unique_ptr<Command> CommandManager::executeUndo()
{
    std::unique_ptr<Command> pCommand = std::move(iUndoList.back());
    iUndoList.pop_back();
    return pCommand;
}

std::unique_ptr<Command> CommandManager::executeRedo()
{
    std::unique_ptr<Command> pCommand = std::move(iRedoList.back());
    iRedoList.pop_back();
    return pCommand;
}

bool CommandManager::issueCommand(std::unique_ptr<Command> pCommand)
{
    if (pCommand->execute() && pCommand->isUndoable())
    {
        addUndo(std::move(pCommand));
        iRedoList.erase(iRedoList.begin(), iRedoList.end());
        return true;
    }
    return false;
}

bool CommandManager::undo()
{
    if ((!iUndoList.empty()))
    {
        std::unique_ptr<Command> pCommand = executeUndo();
        if (pCommand->unExecute()) {
            addRedo(std::move(pCommand));
        }
        else {
            undo();
        }
        return true;
    }
    return false;
}

bool CommandManager::redo()
{
    if (!iRedoList.empty())
    {
        std::unique_ptr<Command> pCommand = executeRedo();
        if (pCommand->execute()) {
            addUndo(std::move(pCommand));
        }
        else {
            redo();
        }
        return true;
    }
    return false;
}

void CommandManager::addUndo(std::unique_ptr<Command> pCommand)
{
    iUndoList.push_back(std::move(pCommand));
}

void CommandManager::addRedo(std::unique_ptr<Command> pCommand)
{
    iRedoList.push_back(std::move(pCommand));
}
