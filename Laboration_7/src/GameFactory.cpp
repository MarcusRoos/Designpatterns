//------------------------------------------------------------------------------
// GameFactory.cpp DT063G Design Patterns With C++
// Implementations of concrete factory classes
//------------------------------------------------------------------------------

#include "GameFactory.h"
#include "Obstacle.h"
#include "Action.h"

// Nasty Game
/**
 * Here we implement the actions for the nasty game mode,
 * a vector is declared and then new actions are added to it,
 * the actions added to it are the ones which are meant to be
 * in a nasty game mode.
 * **/
NastyGameFactory *NastyGameFactory::instance = nullptr;
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

/**
 * Here we implement the obstacles for the nasty game mode,
 * a vector is declared and then new obstacles are added to it,
 * the obstacles added to it are the ones which are meant to be
 * in a nasty game mode.
 * **/
vector<Obstacle *> NastyGameFactory::performObstacle() {
    vector<Obstacle *> obstacle;

    obstacle.emplace_back(new Gangster());
    obstacle.emplace_back(new Dragon());
    obstacle.emplace_back(new Bomb());
    obstacle.emplace_back(new Samuray());
    obstacle.emplace_back(new SumoWrestler());

    return obstacle;
}

/**
 * Creates a new player for the nasty game mode, a hero player
 * **/
Player * NastyGameFactory::newPlayer() {
    return new HeroPlayer();
}

/**
 * Sets the title of this game mode, which in this case is a Nasty Game
 * **/
string NastyGameFactory::setTitle() {
    return "Nasty Game";
}

NastyGameFactory* NastyGameFactory::getInstance() {
    {
        if (instance == nullptr)
        {
            instance = new NastyGameFactory();
        }
        return instance;
    }
}

void NastyGameFactory::deAlloc() {
    delete instance;
    instance = nullptr;
}

// Nice Game
/**
 * Here we implement the actions for the nice game mode,
 * a vector is declared and then new actions are added to it,
 * the actions added to it are the ones which are meant to be
 * in a nice game mode.
 * **/
NiceGameFactory *NiceGameFactory::instance = nullptr;
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

/**
 * Here we implement the obstacles for the nice game mode,
 * a vector is declared and then new obstacles are added to it,
 * the obstacles added to it are the ones which are meant to be
 * in a nice game mode.
 * **/
vector<Obstacle *> NiceGameFactory::performObstacle() {
    vector<Obstacle *> obstacle;

    obstacle.emplace_back(new Wizard());
    obstacle.emplace_back(new Wall());
    obstacle.emplace_back(new Elephant());
    obstacle.emplace_back(new DPexam());


    return obstacle;
}

/**
 * Creates a new player for the nice game mode, an ordinary player
 * **/
Player * NiceGameFactory::newPlayer() {
    return new OrdinaryPlayer();
}

/**
 * Sets the title of this game mode, which in this case is a Nice Game
 * **/
string NiceGameFactory::setTitle() {
    return "Nice Game";
}

NiceGameFactory* NiceGameFactory::getInstance() {
    {
        if (instance == nullptr)
        {
            instance = new NiceGameFactory();
        }
        return instance;
    }
}

void NiceGameFactory::deAlloc() {
    delete instance;
    instance = nullptr;
}