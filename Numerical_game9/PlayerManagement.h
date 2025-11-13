#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H

#include "Numerical_Player.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

using namespace std;

class PlayerManager {
private:
    int p1Wins = 0;
    int p2Wins = 0;
    int draws = 0;

public:
    PlayerManager();

    // Record results
    void recordWin(int playerNumber);
    void recordDraw();

    // Show stats
    void showStats() const;

    // Random move logic for computer
    int getRandomMove(const vector<int>& availableNumbers);
};

#endif
