//------------------------------------------------------------------------------
// GameFactory.cpp DT063G Design Patterns With C++
// Implementations of concrete factory classes
//------------------------------------------------------------------------------

#include "GameFactory.h"
#include "Obstacle.h"
#include "Action.h"

// Nasty Game
vector<Action *> NastyGameFactory::performAction() {
    vector<Action *> action;
    action.emplace_back(new ChainsawAction());
    action.emplace_back(new SwordAction());
    action.emplace_back(new RifleAction());
    action.emplace_back(new BargainAndBuyAction());
    action.emplace_back(new BowAndShakeHandsAction());
    action.emplace_back(new RunAndHideAction());
    action.emplace_back(new CastAspellAction());
    action.emplace_back(new ClimbAction());
    action.emplace_back(new OfferFoodAction());
    action.emplace_back(new SurrenderAction());

    return action;
}

vector<Obstacle *> NastyGameFactory::performObstacle() {
    vector<Obstacle *> obstacle;

    obstacle.emplace_back(new Gangster());
    obstacle.emplace_back(new Dragon());
    obstacle.emplace_back(new Bomb());
    obstacle.emplace_back(new Samuray());
    obstacle.emplace_back(new SumoWrestler());

    return obstacle;
}

Player * NastyGameFactory::newPlayer() {
    return new HeroPlayer();
}

string NastyGameFactory::setTitle() {
    return "Nasty Game";
}

// Nice Game
vector<Action *> NiceGameFactory::performAction() {
    vector<Action *> action;
    action.emplace_back(new ChainsawAction());
    action.emplace_back(new BargainAndBuyAction());
    action.emplace_back(new BowAndShakeHandsAction());
    action.emplace_back(new RunAndHideAction());
    action.emplace_back(new CastAspellAction());
    action.emplace_back(new ClimbAction());
    action.emplace_back(new SurrenderAction());

    return action;
}

vector<Obstacle *> NiceGameFactory::performObstacle() {
    vector<Obstacle *> obstacle;

    obstacle.emplace_back(new Wizard());
    obstacle.emplace_back(new Wall());
    obstacle.emplace_back(new Elephant());
    obstacle.emplace_back(new DPexam());


    return obstacle;
}

Player * NiceGameFactory::newPlayer() {
    return new OrdinaryPlayer();
}

string NiceGameFactory::setTitle() {
    return "Nice Game";
}
