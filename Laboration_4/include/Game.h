//------------------------------------------------------------------------------
// Game.h DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include "Action.h"
#include "Obstacle.h"
#include "GameFactory.h"

using std::vector;

class Action;
class Obstacle;
class GameFactory;


class Game{
 private:
    string title;
    vector<Obstacle*> obstacles;  // Obstacles to overcome in the game
    vector<Action*> actions;  // Possible actions the player may perform
    Player* player;

 public:
    explicit Game(GameFactory *gFact);  // gFact is a concrete factory-object
    ~Game();
    void play();  // Play the game
};
