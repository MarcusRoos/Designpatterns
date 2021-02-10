//
// Created by Marcus Roos on 2021-02-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT063G_HANOIENGINE_H
#define DT063G_HANOIENGINE_H

#include <deque>
#include <iostream>

class HanoiEngine {
    enum {T1, T2, T3};
    int iDiscs;
    int iMoves;
    std::deque<int> iTowers[3];
public:
    explicit HanoiEngine(int aDiscs = 5); // aDiscs is the nr of discs
    ~HanoiEngine()= default;

    // Display the towers with the discs
    void show(std::ostream &aStrm = std::cout);

    // Move a disc from tower aFrom to tower aTo.
    // A successful move returns true
    bool move(int aFrom, int aTo);

    // Reset the game, start with aDiscs discs
    void reset(int aDiscs);

    // Is the game successfully finished?
    bool isDone();

};


#endif //DT063G_HANOIENGINE_H
