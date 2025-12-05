/**
 * @file Pyramid_UI.h
 * @brief UI class for the Pyramid Tic-Tac-Toe variant.
 */

#ifndef PYRAMID_UI_H
#define PYRAMID_UI_H

#include "BoardGame_Classes.h"
#include "Pyramid_Board.h"

 /**
  * @class PyramidUI
  * @brief Handles user interaction for the Pyramid game mode.
  */
class PyramidUI : public UI<char> {
public:

    /**
     * @brief Initializes UI with title and board size.
     */
    PyramidUI();

    /**
     * @brief Creates a player with name, symbol, and type.
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Reads and returns a player's move.
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Displays the rules specific to the Pyramid game.
     */
    void display_rules();
};

#endif
