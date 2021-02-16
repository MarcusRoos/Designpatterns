//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_CONCRETEDECORATORS_H
#define DT063G_CONCRETEDECORATORS_H

#include "MainComponent.h"
#include "ConcreteComponents.h"
#include <memory>

/**
Class ConcreteDecorators, extends the public interface MainComponent.
 Has a shared pointer as private member to determine which component will
 be added to the drink next.

*/
class ConcreteDecorators : public ConcreteComponent{
private:
    std::shared_ptr<MainComponent> nextComponent;
public:
    /**
Explicit constructor, constructs the class

@param Shared pointer of type MainComponent
@return none
*/
    explicit ConcreteDecorators(std::shared_ptr<MainComponent> component);
    /**
Returns the name as a string

@param None
@return string
*/
    std::string getName() override;
    /**
Returns the price as a double

@param None
@return double
*/
    double getPrice() override;
};

/**
Class Sugar, extends the public interface ConcreteDecorators.
Will keep adding components to the drink until satisfaction.

*/
class Sugar : public ConcreteDecorators{
public:
    /**
Explicit constructor, constructs the class

@param Shared pointer of type MainComponent
@return none
*/
    explicit Sugar(const std::shared_ptr<MainComponent>& component);
    /**
Returns the name as a string

@param None
@return string
*/
    std::string getName() override;
    /**
Returns the price as a double

@param None
@return double
*/
    double getPrice() override;
};

/**
Class Milk, extends the public interface ConcreteDecorators.
Will keep adding components to the drink until satisfaction.

*/
class Milk : public ConcreteDecorators{
public:
    /**
Explicit constructor, constructs the class

@param Shared pointer of type MainComponent
@return none
*/
    explicit Milk(const std::shared_ptr<MainComponent>& component);
    /**
Returns the name as a string

@param None
@return string
*/
    std::string getName() override;
    /**
Returns the price as a double

@param None
@return double
*/
    double getPrice() override;
};

/**
Class Cream, extends the public interface ConcreteDecorators.
Will keep adding components to the drink until satisfaction.

*/
class Cream : public ConcreteDecorators{
public:
    /**
Explicit constructor, constructs the class

@param Shared pointer of type MainComponent
@return none
*/
    explicit Cream(const std::shared_ptr<MainComponent>& component);
    /**
Returns the name as a string

@param None
@return string
*/
    std::string getName() override;
    /**
Returns the price as a double

@param None
@return double
*/
    double getPrice() override;
};

/**
Class WhippedCream, extends the public interface ConcreteDecorators.
Will keep adding components to the drink until satisfaction.

*/
class WhippedCream : public ConcreteDecorators{
public:
    /**
Explicit constructor, constructs the class

@param Shared pointer of type MainComponent
@return none
*/
    explicit WhippedCream(const std::shared_ptr<MainComponent>& component);
    /**
Returns the name as a string

@param None
@return string
*/
    std::string getName() override;
    /**
Returns the price as a double

@param None
@return double
*/
    double getPrice() override;
};

#endif //DT063G_CONCRETEDECORATORS_H
