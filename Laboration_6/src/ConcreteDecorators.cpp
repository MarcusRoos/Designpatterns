//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#include "ConcreteDecorators.h"

ConcreteDecorators::ConcreteDecorators(
        std::unique_ptr<MainComponent> component) :
        nextComponent(std::move(component)) {
}

std::string ConcreteDecorators::getName() {
    return nextComponent->getName();
}

double ConcreteDecorators::getPrice() {
    return nextComponent->getPrice();
}

Sugar::Sugar(std::unique_ptr<MainComponent> component) :
ConcreteDecorators(std::move(component)) {}

std::string Sugar::getName() {
    return ConcreteDecorators::getName() + "Sugar";
}

double Sugar::getPrice() {
    return ConcreteDecorators::getPrice() + 1;
}

Milk::Milk(std::unique_ptr<MainComponent> component) :
        ConcreteDecorators(std::move(component)) {}

std::string Milk::getName() {
    return ConcreteDecorators::getName() + "Milk";
}

double Milk::getPrice() {
    return ConcreteDecorators::getPrice() + 1;
}

Cream::Cream(std::unique_ptr<MainComponent> component) :
        ConcreteDecorators(std::move(component)) {}

std::string Cream::getName() {
    return ConcreteDecorators::getName() + "Cream";
}

double Cream::getPrice() {
    return ConcreteDecorators::getPrice() + 2;
}

WhippedCream::WhippedCream(std::unique_ptr<MainComponent> component) :
        ConcreteDecorators(std::move(component)) {}

std::string WhippedCream::getName() {
    return ConcreteDecorators::getName() + "WhippedCream";
}

double WhippedCream::getPrice() {
    return ConcreteDecorators::getPrice() + 5;
}

