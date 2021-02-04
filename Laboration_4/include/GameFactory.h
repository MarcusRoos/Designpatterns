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
    virtual vector <std::unique_ptr<Action>> performAction() = 0;
    virtual vector <std::unique_ptr<Obstacle>> performObstacle() = 0;
};


/**
     * NastyGameFactory:
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
