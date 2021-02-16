//
// Created by Marcus Roos on 2021-02-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_MAINCOMPONENT_H
#define DT063G_MAINCOMPONENT_H
#include <string>

/** Main Component class, contains three pure virtual functions.
 * One to get the name as a string, one to get the price, and
 * a default destructor.
 * */
class MainComponent{
public:
    /**
Pure virtual function getName, will be implemented in the different
     drinks and extras classes.

@param None
@return string
*/
    virtual std::string getName() = 0;
    /**
Pure virtual function getPrice, will be implemented in the different
 drinks and extras classes.

@param None
@return double
*/
    virtual double getPrice() = 0;
    /**
Default destructor

@param None
@return None
*/
    virtual ~MainComponent() = default;
};

#endif //DT063G_MAINCOMPONENT_H
