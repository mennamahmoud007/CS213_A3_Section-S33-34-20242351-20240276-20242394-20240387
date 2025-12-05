/**
 * @file Obstacles_UI.h
 * @brief User interface class for the Obstacles Tic-Tac-Toe variant.
 */

#ifndef OBSTACLES_UI_H
#define OBSTACLES_UI_H

#include "BoardGame_Classes.h"
#include "obstacles_Board.h"

 /**
  * @class ObstaclesUI
  * @brief Handles user input and output for the Obstacles game mode.
  */
class ObstaclesUI : public UI<char> {
public:

    /**
     * @brief Constructor initializing UI with title and board size.
     */
    ObstaclesUI();

    /**
     * @brief Creates a player with a name, symbol, and type.
     * @param name Player name
     * @param symbol Player symbol
     * @param type HUMAN or AI
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Reads and returns the player's move.
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Displays the rules of the Obstacles game mode.
     */
    void display_rules();
};

#endif
