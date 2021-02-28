//------------------------------------------------------------------------------
// Game.cpp DT063G Design Patterns With C++
// Implementation of Game
//------------------------------------------------------------------------------

#include <iostream>
#include "Game.h"

using std::cin;

template<typename T>
void destroyVectorElements(vector<T> &vec);

/**
 * A new game factory object is passed down as a raw pointer to this function,
 * this object is used to load the actions, obstacles, player and title
 * values. The parameter passed down to this function will either be a
 * nice or nasty game.**/
Game::Game(GameFactory *gFact) {
    actions = gFact->performAction();
    obstacles = gFact->performObstacle();
    player = gFact->newPlayer();
    title = gFact->setTitle();

}

Game::~Game() {
    destroyVectorElements(obstacles);
    destroyVectorElements(actions);
    delete player;
}


void Game::play() {
    cout << "*** Welcome to " << title << " ***" << endl;

    typedef std::vector<Action*>::iterator AtypeIt;
    typedef std::vector<Obstacle*>::iterator OtypeIt;

    AtypeIt aStart = actions.begin(), aStop = actions.end(), ait;
    OtypeIt oStart = obstacles.begin(), oStop = obstacles.end(), oit;

    for (oit = oStart; oit != oStop && player->alive(); ++oit) {
        int alt, choice;
        bool passed = false;

        while (!passed && player->alive()) {
            (*oit)-> show();
            cout <<"\nChoose action:\n";

            for (alt = 1, ait=aStart; ait != aStop && player->alive(); ++alt, ++ait)
                cout << "\t " << alt << ' '<< (*ait)->show();

            while (!(cin >> choice) || choice <1 || choice >=alt) {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }

            passed = (*oit)->tryToPass(player, actions[choice-1]);
            player->show();
        }   // while
    }
    if (player->alive())
        cout << "\nYou Win!" << endl;
    else
        cout << "\nYou Lose!" << endl;
    cin.ignore(cin.rdbuf()->in_avail());
}


/**
 * Added a way to destroy all the leftover raw pointers. **/
template<typename T>
void destroyVectorElements(vector<T> &vec) {
    for (int i=0; i<vec.size(); i++){
        delete vec[i];
    }
}
