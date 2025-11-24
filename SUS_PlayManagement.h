#ifndef SUS_PLAYMANAGEMENT_H
#define SUS_PLAYMANAGEMENT_H

#include "SUS_Board.h"
#include "SUS_Player.h"

class SUS_PlayManagement {
private:
    SUS_Board board;
    SUS_Player p1;
    SUS_Player p2;

    int bestScore; // maximum SUS patterns possible
    vector<vector<char>> bestBoard;

public:
    SUS_PlayManagement(SUS_Player a, SUS_Player b);

    void simulateGame();       // recursion entry
    void rec(bool turn);       // backtracking + recursion

    void printBest();
};

#endif
