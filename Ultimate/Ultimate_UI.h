#ifndef ULTIMATE_UI_H
#define ULTIMATE_UI_H

#include "BoardGame_Classes.h"
#include "Ultimate_Board.h"
#include <string>

/**
 * @class Ultimate_UI
 * @brief Handles UI interaction for Ultimate Tic Tac Toe.
 */
class Ultimate_UI : public UI<char> {
public:
    /** Constructor */
    Ultimate_UI();

    /**
     * @brief Create a player for the Ultimate Board game.
     * @param name Player name.
     * @param symbol Player symbol (X or O).
     * @param type Human or AI.
     * @return Pointer to created player.
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Get player's move: select sub-board + cell inside it.
     * @param player Pointer to current player.
     * @return Pointer to Move object.
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Overridden display for custom Ultimate board printing.
     */
    void display_board_matrix(const vector<vector<char>>& matrix) const override {
        // Made virtual in framework so Ultimate_UI can override it
    }

    /**
     * @brief Display Ultimate Tic Tac Toe rules.
     */
    void display_rules();
};

#endif
