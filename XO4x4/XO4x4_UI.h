#ifndef XO4x4_UI_H
#define XO4x4_UI_H

#include "BoardGame_Classes.h"
#include "XO4x4_Board.h"

/**
 * @class XO4x4_UI
 * @brief User interface controller for the 4x4 Tic-Tac-Toe variant.
 */
class XO4x4_UI : public UI<char> {
public:
    /** Constructor */
    XO4x4_UI();

    /**
     * @brief Create a player (Human or AI).
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Get the user's move (place or move piece).
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Display the rules of 4x4 XO variant.
     */
    void display_rules();
};

#endif
