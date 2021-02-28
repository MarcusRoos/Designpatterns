//------------------------------------------------------------------------------
// GameFactory.h DT063G Design Patterns With C++
// GameFactory is an abstract class which defines an interface for
// derived concrete classes
//------------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;

class Player;
class Obstacle;
class Action;

/**
 Class GameFactory

Pure virtual class, functions will be implemented in nasty and nice game
 */

class GameFactory {
protected:
    /**
* Default constructor of class GameFactory
*
* @param None
* @return None.
*/
    GameFactory() = default;

public:
    /**
* Default destructor of class GameFactory
*
* @param None
* @return None.
*/
    virtual ~GameFactory() = default;
    /**
* Virtual function of performAction
*
* @param None
* @return Raw pointer of type Action.
*/
    virtual vector <Action *> performAction() = 0;
    /**
* Virtual function of performObstacle
*
* @param None
* @return Raw pointer of type Obstacle.
*/
    virtual vector <Obstacle *> performObstacle() = 0;
    /**
* Virtual function of newPlayer
*
* @param None
* @return Raw pointer of type Player.
*/
    virtual Player* newPlayer() = 0;
    /**
* Virtual function of setTitle
*
* @param None
* @return String.
*/
    virtual string setTitle() = 0;
};


// All functions above are implemented in the classes below
class NastyGameFactory : public GameFactory{
public:
    NastyGameFactory()= default;
    ~NastyGameFactory() override = default;
    vector <Action *> performAction() override;
    vector <Obstacle *> performObstacle() override;
    Player * newPlayer() override;
    string setTitle() override;
};

class NiceGameFactory : public GameFactory{
public:
    NiceGameFactory() = default;
    ~NiceGameFactory() override = default;
    vector <Action *> performAction() override;
    vector <Obstacle *> performObstacle() override;
    Player * newPlayer() override;
    string setTitle() override;
};