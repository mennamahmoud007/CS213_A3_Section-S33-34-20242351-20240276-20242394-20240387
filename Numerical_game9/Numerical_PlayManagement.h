#ifndef NUMERICAL_PLAYMANAGEMENT_H
#define NUMERICAL_PLAYMANAGEMENT_H

#include "Numerical_UI.h"
#include "PlayerManagement.h"
#include "Numerical_Board.h"
#include "Numerical_Player.h"
#include <string>

class NumericalPlayManagement {
private:
    NumericBoard board;          // The game board
    NumericalUI ui;              // Handles user interaction
    Player<int>* p1;             // Player 1
    Player<int>* p2;             // Player 2
    Player<int>* currentPlayer;  // Tracks whose turn it is
    PlayerManager playerManager; // Manages players and stats

    void switchPlayer();

public:
    NumericalPlayManagement();
    ~NumericalPlayManagement();
    void run();
};

#endif // NUMERICAL_PLAYMANAGEMENT_H
