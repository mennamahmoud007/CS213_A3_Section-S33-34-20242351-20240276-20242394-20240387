#ifndef MEMORY_UI_H
#define MEMORY_UI_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Memory_UI
 * @brief Handles user interface and input for the Memory Tic-Tac-Toe game.
 *
 * This UI interacts with players, receives move coordinates,
 * displays rules, and creates Human/AI players.
 */
class Memory_UI : public UI<char> {
public:
    /** @brief Constructor */
    Memory_UI();

    /**
     * @brief Creates a player (Human or AI)
     * @param name Player name
     * @param symbol Symbol used by the player ('X'/'O')
     * @param type PlayerType (Human/AI)
     * @return Pointer to created player
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Gets a move from the player
     * @param player Pointer to the current player
     * @return Pointer to Move object containing (row, col)
     */
    Move<char>* get_move(Player<char>* player) override;

    /** @brief Displays game rules for Memory Tic-Tac-Toe */
    void display_rules();
};

#endif
