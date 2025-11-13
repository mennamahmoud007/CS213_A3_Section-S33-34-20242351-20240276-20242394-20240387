#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H

#include "Numerical_Player.h"
#include "Numerical_Board.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

class PlayerManager {
public:
    PlayerManager();
    ~PlayerManager();

    // Create/add a player. The manager takes ownership of the returned Player pointer.
    // If oddAllowed is omitted, manager will default to odd for the first player and even for second.
    Player<int>* addPlayer(const string& name, int sym, PlayerType type, bool oddAllowed = true);

    // For CPU players: choose a random valid move (returns allocated Move<int>* that caller must delete)
    Move<int>* getRandomMove(NumericBoard& board, Player<int>* player);

    // Stats
    void recordWin(Player<int>* p);
    void recordDraw();
    void showAllPlayers() const;

    // helper to clear players
    void clear();

private:
    vector<Player<int>*> players;
    std::map<Player<int>*, int> wins;
    int draws;
};

#endif // PLAYERMANAGEMENT_H
