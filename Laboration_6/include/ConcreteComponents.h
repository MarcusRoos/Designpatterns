//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_CONCRETECOMPONENTS_H
#define DT063G_CONCRETECOMPONENTS_H

#include "MainComponent.h"

class Coffee : public MainComponent{
public:
    Coffee() = default;
    std::string getName() override {return "Coffee";}
    double getPrice() override {return 10;}
};

class Espresso : public MainComponent{
public:
    Espresso() = default;
    std::string getName() override {return "Espresso";}
    double getPrice() override {return 14;}
};

class Tea : public MainComponent{
public:
    Tea() = default;
    std::string getName() override {return "Tea";}
    double getPrice() override {return 10;}
};

class Chocolate : public MainComponent{
public:
    Chocolate() = default;
    std::string getName() override {return "Chocolate";}
    double getPrice() override {return 12;}
};

#endif //DT063G_CONCRETECOMPONENTS_H
