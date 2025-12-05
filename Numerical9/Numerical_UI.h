/**
 * @file Numerical_UI.h
 * @brief UI class for handling the Numerical Tic-Tac-Toe game interactions.
 */

#ifndef NUMERICAL_UI_H
#define NUMERICAL_UI_H

#include "BoardGame_Classes.h"
#include "Numerical_Board.h"
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

/**
 * @class NumericalUI
 * @brief Provides user interface for the Numerical Game (input/output).
 */
class NumericalUI : public UI<int> {
public:

    /**
     * @brief Constructor initializes the UI with a custom welcome message.
     */
    NumericalUI() : UI<int>("Welcome to our Numerical Game", 3) {}

    /**
     * @brief Creates a player with a name + symbol (odd/even).
     * @param name player's name
     * @param symbol odd/even indicator
     * @param type human or computer
     */
    Player<int>* create_player(string& name, int symbol, PlayerType type) override;

    /**
     * @brief Reads a move from the player (row, col, number).
     */
    Move<int>* get_move(Player<int>* player) override;

    /**
     * @brief Displays full game rules.
     */
    void display_rules();
};

#endif
