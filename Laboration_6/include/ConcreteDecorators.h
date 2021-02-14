//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_CONCRETEDECORATORS_H
#define DT063G_CONCRETEDECORATORS_H

#include "MainComponent.h"
#include <memory>

class ConcreteDecorators : public MainComponent{
private:
    std::unique_ptr<MainComponent> nextComponent;
public:
    explicit ConcreteDecorators(std::unique_ptr<MainComponent> component);
    std::string getName() override;
    double getPrice() override;
};

class Sugar : public ConcreteDecorators{
public:
    explicit Sugar(std::unique_ptr<MainComponent> component);
    std::string getName() override;
    double getPrice() override;
};

class Milk : public ConcreteDecorators{
public:
    explicit Milk(std::unique_ptr<MainComponent> component);
    std::string getName() override;
    double getPrice() override;
};

class Cream : public ConcreteDecorators{
public:
    explicit Cream(std::unique_ptr<MainComponent> component);
    std::string getName() override;
    double getPrice() override;
};

class WhippedCream : public ConcreteDecorators{
public:
    explicit WhippedCream(std::unique_ptr<MainComponent> component);
    std::string getName() override;
    double getPrice() override;
};

#endif //DT063G_CONCRETEDECORATORS_H
