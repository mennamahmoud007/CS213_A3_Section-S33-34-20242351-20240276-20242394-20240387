#ifndef DIAMOND_BOARD_H
#define DIAMOND_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>

using namespace std;

/**
 * @class Diamond_Board
 * @brief Represents a Diamond-shaped Tic-Tac-Toe board.
 *
 * Inherits from Board<char>. Handles game logic specific to the Diamond Tic-Tac-Toe variant,
 * including checking for wins, losses, draws, valid moves, and board updates.
 */
class Diamond_Board : public Board<char> {
private:
    char blank = '.';  /**< Symbol for an empty cell */
    char invalid = ' ';  /**< Symbol for invalid/out-of-board cell */
    int center = 4;     /**< Index of the center row/column */

    /**
     * @brief Checks if a cell (r, c) is valid on the diamond-shaped board.
     * @param r Row index
     * @param c Column index
     * @return true if valid, false otherwise
     */
    bool valid_cell(int r, int c) const;

    /**
     * @brief Finds directions where a line of given length exists for a symbol.
     * @param sym The player's symbol
     * @param length Length of line to check
     * @return Vector of directions (as integers) where line exists
     */
    vector<int> find_line_directions(char sym, int length) const;

public:
    /** @brief Constructor: initializes the Diamond board */
    Diamond_Board();

    /** @brief Destructor */
    virtual ~Diamond_Board();

    /**
     * @brief Applies a move to the board
     * @param move Pointer to the Move object
     * @return true if move is applied successfully, false otherwise
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Checks if the given player has won
     * @param player Pointer to the Player object
     * @return true if player wins, false otherwise
     */
    bool is_win(Player<char>* player) override;

    /**
     * @brief Checks if the given player has lost
     * @param player Pointer to the Player object
     * @return true if player loses, false otherwise
     */
    bool is_lose(Player<char>* player) override;

    /**
     * @brief Checks if the game is a draw for the given player
     * @param player Pointer to the Player object
     * @return true if draw, false otherwise
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Checks if the game is over for the given player
     * @param player Pointer to the Player object
     * @return true if game over, false otherwise
     */
    bool game_is_over(Player<char>* player) override;

    /** @brief Displays the board on the console */
    void display_board();

    /** @brief Gets the symbol at a specific cell */
    char get_cell(int r, int c) const { return board[r][c]; }

    /** @brief Applies a move at row r and column c for the given symbol */
    void apply_move(int r, int c, char sym);

    /** @brief Undoes a move at row r and column c */
    void undo_move(int r, int c);

    /** @brief Returns a vector of coordinates of empty cells */
    vector<pair<int, int>> get_empty_cells() const;
};

#endif