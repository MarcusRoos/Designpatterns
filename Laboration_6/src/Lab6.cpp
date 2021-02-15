//------------------------------------------------------------------------------
// Lab6.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include <iostream>
#include "memstat.hpp"
#include "MainComponent.h"
#include "ConcreteComponents.h"
#include "ConcreteDecorators.h"
#include <memory>
#include <string>
#include <iomanip>


int main()
{
    std::shared_ptr<MainComponent> component;
    int drinkChoice;
    std::string drink;

    bool mainLoop = true;
    while (mainLoop)
    {
        bool finished = false;
        std::cout << "======= COFFEE MACHINE ======= " << std::endl;
        std::cout << "Which drink would you like to order?" << std::endl;
        std::cout << "1. Coffee 10kr" << std::endl;
        std::cout << "2. Espresso 14kr" << std::endl;
        std::cout << "3. Tea 10kr" << std::endl;
        std::cout << "4. Chocolate 12kr" << std::endl;
        std::cout << "5. DONE" << std::endl;
        std::cout << "Choice: ";
        std::cin >> drinkChoice;
        while (std::cin.fail() || drinkChoice < 0 || drinkChoice > 5) {
            std::cout << "Wrong input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> drinkChoice;
        }
        switch (drinkChoice)
        {
            case 1:
            {
                component = std::make_shared<Coffee>();
                drink = component->getName();
                break;
            }
            case 2:
            {
                component = std::make_shared<Espresso>();
                drink = component->getName();
                break;
            }
            case 3:
            {
                component = std::make_shared<Tea>();
                drink = component->getName();
                break;
            }
            case 4:
            {
                component = std::make_shared<Chocolate>();
                drink = component->getName();
                break;
            }
            case 5:
            {
                default:
                    mainLoop = false;
                finished = true;
                break;
            }
        }
        bool print = true;
        while (!finished)
        {
            int decoratorChoice = 0;
            if (print) {
                std::cout << "Please choose toppings for your " <<
                          drink << std::endl << std::endl;
                print = false;
            }
            else {
                std::cout << "Would you like additional toppings for your " <<
                          drink << "?" << std::endl << std::endl;
            }
            std::cout << "1. Sugar 1kr" << std::endl;
            std::cout << "2. Milk 1kr" << std::endl;
            std::cout << "3. Cream 2kr" << std::endl;
            std::cout << "4. Whipped Cream 5kr" << std::endl;
            std::cout << "5. Show current order" << std::endl;
            std::cout << "6. DONE" << std::endl;
            std::cout << "Choice: ";
            std::cin >> decoratorChoice;
            while (std::cin.fail() || decoratorChoice < 0 || decoratorChoice > 6) {
                std::cout << "Wrong input.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> decoratorChoice;
            }

            switch (decoratorChoice)
            {
                case 1:
                {
                    component = std::unique_ptr<Sugar> (new Sugar(component));
                    break;
                }
                case 2:
                {
                    component = std::unique_ptr<Milk> (new Milk(component));
                    break;
                }
                case 3:
                {
                    component = std::unique_ptr<Cream> (new Cream(component));
                    break;
                }
                case 4:
                {
                    component = std::unique_ptr<WhippedCream> (new WhippedCream(component));
                    break;
                }
                case 5:
                {
                    std::cout << "Your current order is: " <<
                    component->getName() << ". Which would cost: "
                              << std::fixed << std::setprecision(2)
                              << component->getPrice()
                              << "kr" << std::endl;
                    break;
                }
                case 6:
                {
                    default:
                        finished = true;
                    break;
                }
            }
        }
        if (component) {
            std::cout << "Your order: " << component->getName() << ". Cost: "
                      << std::fixed << std::setprecision(2)
                      << component->getPrice()
                      << "kr" << std::endl;
        }
    }

    return 0;
}
