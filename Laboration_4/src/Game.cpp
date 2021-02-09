//------------------------------------------------------------------------------
// Game.cpp DT063G Design Patterns With C++
// Implementation of Game
//------------------------------------------------------------------------------

#include <iostream>
#include "Game.h"

using std::cin;

template<typename T>
void destroyVectorElements(vector<T> &vec);


Game::Game(GameFactory *gFact) {
    actions = gFact->performAction();
    obstacles = gFact->performObstacle();
    player = gFact->newPlayer();
    title = gFact->setTitle();
    /**
     * gFact points to a concrete Factory-object which needs to perform the operations.
     *
     * makeObstacles:
     * Fill 'obstacles' with pointers to the game's Obstacle-objects!
     *
     * makeActions:
     * Fill 'actions' with pointers to the Action-objects the player may choose from
     *
     * makePlayer:
     * Assign 'player' a pointer to a concrete Player-object
     *
     * Give 'title' a suitable name
     */
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


template<typename T>
void destroyVectorElements(vector<T> &vec) {
    // TODO(student): implementation
}
