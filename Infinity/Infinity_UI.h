#ifndef INFINITY_UI_H
#define INFINITY_UI_H

#include "BoardGame_Classes.h"
#include "Infinity_Board.h"
using namespace std;

/**
 * @class Infinity_UI
 * @brief Handles user interaction for Infinity Tic-Tac-Toe.
 *
 * Provides input prompts, rule display, and ties the board logic
 * with the player system. Does not contain AI logic since this mode
 * is usually player vs player.
 */
class Infinity_UI : public UI<char> {
public:
    /** @brief Constructor */
    Infinity_UI();

    /**
     * @brief Creates a player (Human or AI)
     * @param name Player name
     * @param symbol Character symbol used by the player
     * @param type PlayerType enum (Human/AI)
     * @return Pointer to newly created player
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Gets a move from the player through console input
     * @param player Pointer to current player
     * @return Pointer to a Move object
     */
    Move<char>* get_move(Player<char>* player) override;

    /** @brief Displays rules of Infinity Tic-Tac-Toe */
    void display_rules();
};

#endif
