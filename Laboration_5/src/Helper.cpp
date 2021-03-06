//
// Created by Marcus Roos on 2021-02-22.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Helper.h"

int reset()
{
    remove("Hanoi.log");
    int discs;
    std::cout << "How many discs should the towers be loaded with?: ";
    std::cin >> discs;
    std::cin.get();

    ofstream logfile;
    logfile.open("Hanoi.log");
    if (logfile.is_open())
    {
        logfile << discs << '\n';
    }
    logfile.close();
    return discs;
}

int printMainMenu(){
    std::cout << "Choose your next Hanoi move:" << std::endl;
    std::cout << "1 - Move" << std::endl;
    std::cout << "2 - Show" << std::endl;
    std::cout << "3 - Undo" << std::endl;
    std::cout << "4 - Redo" << std::endl;
    std::cout << "5 - Reset" << std::endl;
    std::cout << "6 - Quit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > 6) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    return choice;
}

int printReplayMenu(){
    std::cout << "=========== Hanoi game =========== " << endl;
    std::cout << "1 - Replay previous game" << endl;
    std::cout << "2 - New game" << endl;
    std::cout << "Choice: ";
    int choice = 0;
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > 2) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    return choice;
}

void printMainProgram(){
    int choice=0;
    std::unique_ptr<CommandManager> Cmdmanager (new CommandManager());

    ifstream logfile;
    logfile.open("Hanoi.log");
    if (!logfile.is_open()) {
        std::cout << "No previous game saved" << std::endl;
    }
    else {
        choice = printReplayMenu();
        std::string amountOfDiscs;
        logfile >> amountOfDiscs;
        switch (choice) {
            case 1: {
                std::cout << "Number of discs: " << amountOfDiscs << std::endl;
                HanoiEngine gameEngine(stoi(amountOfDiscs));
                Replay replaying(gameEngine);
                replaying.readlog();
                pauseFunction();
                break;
            }
            case 2: {
                default:
                    break;
            }
        }
        logfile.close();
    }


    HanoiEngine engine(3);

    Cmdmanager->issueCommand(std::unique_ptr<ResetCommand>
                                     (new ResetCommand(engine, reset())));

    bool gameLoop = true;
    while (gameLoop)
    {
    choice = printMainMenu();
        switch (choice)
        {
            case 1:
                int fromTower, toTower;
                std::cout << "Move from tower: ";
                std::cin >> fromTower;
                std::cin.get();
                std::cout << "Move to tower: ";
                std::cin >> toTower;
                std::cin.get();
                Cmdmanager->issueCommand(
                        std::unique_ptr<MoveCommand> (
                                new MoveCommand(engine, fromTower, toTower)));
                break;
            case 2:
                Cmdmanager->issueCommand(
                        std::unique_ptr<ShowCommand> (
                                new ShowCommand(engine)));
                break;
            case 3:
                Cmdmanager->undo();
                Cmdmanager->issueCommand(
                        std::unique_ptr<ShowCommand> (
                                new ShowCommand(engine, false)));
                break;
            case 4:
                Cmdmanager->redo();
                Cmdmanager->issueCommand(
                        std::unique_ptr<ShowCommand> (
                                new ShowCommand(engine, false)));
                break;
            case 5:
                Cmdmanager->issueCommand(
                        std::unique_ptr<ResetCommand> (
                                new ResetCommand(engine, reset())));
                break;
            case 6:
            default:
                gameLoop = false;
                break;
        }
    }
}