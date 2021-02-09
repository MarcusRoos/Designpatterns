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


class GameFactory {
 protected:
    GameFactory() = default;

 public:
    virtual ~GameFactory() = default;
    virtual vector <Action *> performAction() = 0;
    virtual vector <Obstacle *> performObstacle() = 0;
    virtual Player* newPlayer() = 0;
    virtual string setTitle() = 0;
};



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
/**
*
* Suitable operations
* (implementations of GameFactory.cpp)
*
* Obstacles:
* Dragon, Bomb, Samuray, SumoWrestler, Gangster
*
* Possible Actions:
* BowAndShakeHandsAction, RunAndHideAction, SwordAction, RifleAction,
* OfferFoodAction, ChainsawAction, CastAspellAction, BargainAndBuyAction, SurrenderAction
*
* Player:
* HeroPlayer
*/

/**
     * NiceGameFactory:
     *
     * Suitable operations
     * (implementations of GameFactory.cpp)
     *
     * Obstacles:
     * Wizard, Wall, Elephant, DPexam
     *
     * Possible Actions:
     * BowAndShakeHandsAction, RunAndHideAction, BargainAndBuyAction,
     * ChainsawAction, ClimbAction, CastAspellAction, SurrenderAction
     *
     * Player:
     * OrdinaryPlayer
     */
