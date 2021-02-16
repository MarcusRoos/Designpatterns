//
// Created by Marcus Roos on 2021-02-16.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Helper.h"

using std::cout;
using std::endl;

int printVehicleMenu(){
    // Sets vehicle type
    std::cout << "===== Choose your vehicle test =====" << std::endl;
    std::cout << "1. Car" << std::endl;
    std::cout << "2. Submarine" << std::endl;
    std::cout << "3. SpaceShuttle" << std::endl;
    std::cout << "Enter choice" << std::endl;
    int vehicleIdx = 0;
    std::cin >> vehicleIdx;
    while (std::cin.fail() || vehicleIdx < 1 || vehicleIdx > 3) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> vehicleIdx;
    }
    return vehicleIdx;
}
int printEngineMenu() {
    std::cout << "===== Choose your engine test =====" << std::endl;
    std::cout << "1. V8 engine" << std::endl;
    std::cout << "2. Gas turbine" << std::endl;
    std::cout << "3. Fuel cell" << std::endl;
    std::cout << "Enter choice" << std::endl;
    int sourceIdx = 0;
    std::cin >> sourceIdx;
    while (std::cin.fail() || sourceIdx < 1 || sourceIdx > 3) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> sourceIdx;
    }
    return sourceIdx;
}

int printRetry(){
    std::cout << "Rego?" << std::endl;
    std::cout << "1. Yes. " << std::endl;
    std::cout << "0. Nah. " << std::endl;
    int retry = 0;
    std::cin >> retry;
    while (std::cin.fail() || retry < 0 || retry > 1) {
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> retry;
    }
    return retry;
}

void mainProgram(){
    bool again = true;
    do {
        // Adds power sources and vehicles to their respect vector of pointers
        std::vector<std::unique_ptr<PowerSource>> powerSource;
        std::vector<std::unique_ptr<Vehicle>> vehicleType;
        // Fill up the vectors
        powerSource.emplace_back(new V8ClassicAD());
        powerSource.emplace_back(new GasTurbineAD());
        powerSource.emplace_back(new FuelCellAD());

        int vehicleIdx=0;
        vehicleIdx = printVehicleMenu();

        int sourceIdx=0;
        sourceIdx = printEngineMenu();
        std::shared_ptr<PowerSource> src = std::move(powerSource[sourceIdx-1]);
        vehicleType.emplace_back(new Car(src));
        vehicleType.emplace_back(new Submarine(src));
        vehicleType.emplace_back(new SpaceShuttle(src));
        // Sets vehicle in accordance to user choice
        // Sets power source
        // Sets the power source in accordance to user choice
        std::unique_ptr<Vehicle> chosenVehicle(move(vehicleType[vehicleIdx - 1]));

        std::cout << "Vehicle: " + chosenVehicle->toString() << std::endl <<
                  "Power Source: " << chosenVehicle->poweredBy() << std::endl
                  << std::endl;

        // Drives the vehicles
        chosenVehicle->drive();

        // Asks if the user wants to continue the program or quit
        int retry = 0;
        retry = printRetry();
        switch(retry) {
            case 1:
                break;
            case 0:
            default:
                again = false;
                break;
        }


    }while(again);
}