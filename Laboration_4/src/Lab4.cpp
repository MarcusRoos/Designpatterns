//------------------------------------------------------------------------------
// Lab4.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "Lab4.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "memstat.hpp"

using std::cin;

void gameLoop() {
        int choice;
        bool keepOn = true;

        while (keepOn) {
            GameFactory *gf = nullptr;
            cout << "Choose your game:" << endl;
            cout << "1 - Nice game" << endl;
            cout << "2 - Nasty game" << endl;
            cout << "3 - quit" << endl;

            while (!(cin >> choice) || choice <1 || choice >3) {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }

            switch (choice) {
                // case 1:  gf = Ett factory-objekt: break;
                // case 2:  gf = Ett annat factory-objekt; break;
                case 3: keepOn = false;
                default: break;
            }

            if (keepOn) {
                // Game game(gf);
                // game.play();
                // delete gf;
            }
        }  // while
}

int main() {
    std::cout << getAssignmentInfo() << std::endl;
    // gameLoop();
    return 0;
}
