//------------------------------------------------------------------------------
// Lab3.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

//#include "memstat.hpp"
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <iostream>
#include "PowerSourceAdapters.h"
#include "Vehicle.h"
#include "Car.h"
#include "Submarine.h"
#include "SpaceShuttle.h"


int main()
{
    bool again = true;
    do {
        std::vector<std::unique_ptr<PowerSource>> powerSource;
        std::vector<std::unique_ptr<Vehicle>> vehicleType;

        powerSource.emplace_back(new V8ClassicAD());
        powerSource.emplace_back(new GasTurbineAD());
        powerSource.emplace_back(new FuelCellAD());
        vehicleType.emplace_back(new Car());
        vehicleType.emplace_back(new Submarine());
        vehicleType.emplace_back(new SpaceShuttle());

        // Sets vehicle type
        std::cout << "===== Choose your vehicle test =====" << std::endl;
        std::cout << "1. Car" << std::endl;
        std::cout << "2. Submarine" << std::endl;
        std::cout << "3. SpaceShuttle" << std::endl;
        std::cout << "Enter choice" << std::endl;
        int idx = 0;
        std::cin >> idx;
        while (std::cin.fail() || idx < 1 || idx > 3) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> idx;
        }
        std::unique_ptr<Vehicle> chosenVehicle(move(vehicleType[idx - 1]));

        // Sets power source
        std::cout << "===== Choose your engine test =====" << std::endl;
        std::cout << "1. V8 engine" << std::endl;
        std::cout << "2. Gas turbine" << std::endl;
        std::cout << "3. Fuel cell" << std::endl;
        std::cout << "Enter choice" << std::endl;
        idx = 0;
        std::cin >> idx;
        while (std::cin.fail() || idx < 1 || idx > 3) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> idx;
        }
        chosenVehicle->setPowerSource(move(powerSource[idx-1]));



        std::cout << "Vehicle: " + chosenVehicle->toString() << std::endl <<
        "Engine: " << chosenVehicle->poweredBy() << std::endl
                  << std::endl;

        chosenVehicle->drive();

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
        switch(retry) {
            case 1:
                break;
            case 0:
            default:
                again = false;
                break;
        }
    }while(again);

    return 0;
}
