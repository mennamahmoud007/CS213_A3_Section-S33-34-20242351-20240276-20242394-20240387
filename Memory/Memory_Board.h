#ifndef MEMORY_BOARD_H
#define MEMORY_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Memory_Board
 * @brief Tic-Tac-Toe variation with a hidden board that requires memory.
 *
 * The board stores a separate real 3x3 matrix that represents the true
 * state of the game. The public board seen by players may hide or change
 * information depending on the game rules (implemented in the .cpp file).
 *
 * This class handles move updates, win checking, draw conditions,
 * and game-over detection.
 */
class Memory_Board : public Board<char> {
private:
    char blank_symbol = '.';   /**< Symbol for empty cells */
    char realBoard[3][3];      /**< Internal board storing the actual game state */

public:
    /** @brief Constructor: initializes both internal and visible boards */
    Memory_Board();

    /** @brief Destructor */
    virtual ~Memory_Board();

    /**
     * @brief Updates the board with a new move.
     * @param move Move containing row and column
     * @return true if move was valid, false otherwise
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Checks if the given player has won.
     * @param player Pointer to player object
     * @return true if the player has 3 in a row
     */
    bool is_win(Player<char>* player) override;

    /**
     * @brief Memory mode never considers losing separately.
     * @return Always false
     */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Checks if the board is full and no one won.
     * @return true if draw, false otherwise
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Checks if the game is over (win or draw)
     * @return true if game ended
     */
    bool game_is_over(Player<char>* player) override;

    /**
     * @brief Checks if a specific symbol has won.
     * @param sym Character symbol ('X' or 'O')
     * @return true if symbol has 3-in-a-row
     */
    bool check_winner(char sym);
};

#endif
