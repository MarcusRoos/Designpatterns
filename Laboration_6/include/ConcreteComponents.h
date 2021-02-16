//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_CONCRETECOMPONENTS_H
#define DT063G_CONCRETECOMPONENTS_H

#include "MainComponent.h"
#include <memory>

/**
Class ConcreteComponent, extends the public interface MainComponent.
 Has a shared pointer as private member to determine which component will
 be added to the drink next.

*/
class ConcreteComponent : public MainComponent{
public:
    explicit ConcreteComponent() = default;
    std::string getName() override = 0;
    double getPrice() override = 0;
};

/**
Class Coffee, implement the interface MainComponent, used to
 determine which drink you're currently ordering, as well as
 the price for the current drink.

*/
class Coffee : public ConcreteComponent{
public:
    /**
Default constructor for class Coffee

@param None
@return double
*/
    Coffee() = default;
    /**
Returns the name of the drink, Coffee in this case

@param None
@return string
*/
    std::string getName() override {return "Coffee";}
    /**
Returns the price of the drink, 10 in this case

@param None
@return double
*/
    double getPrice() override {return 10;}
};

/**
Class Espresso, implement the interface MainComponent, used to
 determine which drink you're currently ordering, as well as
 the price for the current drink.

*/
class Espresso : public ConcreteComponent{
public:
    /**
Default constructor for class Espresso

@param None
@return double
*/
    Espresso() = default;
    /**
Returns the name of the drink, Espresso in this case

@param None
@return string
*/
    std::string getName() override {return "Espresso";}
    /**
Returns the price of the drink, 14 in this case

@param None
@return double
*/
    double getPrice() override {return 14;}
};

/**
Class Tea, implement the interface MainComponent, used to
 determine which drink you're currently ordering, as well as
 the price for the current drink.

*/
class Tea : public ConcreteComponent{
public:
    /**
Default constructor for class Tea

@param None
@return double
*/
    Tea() = default;
    /**
Returns the name of the drink, Tea in this case

@param None
@return string
*/
    std::string getName() override {return "Tea";}
    /**
Returns the price of the drink, 10 in this case

@param None
@return double
*/
    double getPrice() override {return 10;}
};

/**
Class Chocolate, implement the interface MainComponent, used to
 determine which drink you're currently ordering, as well as
 the price for the current drink.

*/
class Chocolate : public ConcreteComponent{
public:
    /**
Default constructor for class Chocolate

@param None
@return double
*/
    Chocolate() = default;
    /**
Returns the name of the drink, Chocolate in this case

@param None
@return string
*/
    std::string getName() override {return "Chocolate";}
    /**
Returns the price of the drink, 12 in this case

@param None
@return double
*/
    double getPrice() override {return 12;}
};

#endif //DT063G_CONCRETECOMPONENTS_H
