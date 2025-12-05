#ifndef FOURINAROW_BOARD_H
#define FOURINAROW_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
#include <iostream>
using namespace std;

/**
 * @class FourInARow_Board
 * @brief Represents the board for the Connect 4 game.
 *
 * Handles board updates, win detection, draw conditions,
 * and provides helper methods for the AI such as getting valid columns,
 * finding next empty row, applying and undoing moves.
 */
class FourInARow_Board : public Board<char> {
private:
    vector<vector<char>> board_matrix;   /**< 2D matrix holding the board state */
    const int rows = 6;                  /**< Number of rows in Connect 4 board */
    const int cols = 7;                  /**< Number of columns in Connect 4 board */
    const char blank = ' ';              /**< Symbol representing an empty cell */

public:
    /** @brief Constructor: initializes a 6x7 empty board */
    FourInARow_Board();

    /** @brief Destructor */
    ~FourInARow_Board();

    /**
     * @brief Checks if the given symbol has achieved 4 in a row.
     * @param symbol Player symbol ('X' or 'O')
     * @return true if 4 in a row exists, false otherwise
     */
    bool check_four_in_a_row(char symbol);

    /**
     * @brief Returns a reference to the internal board matrix
     * @return 2D vector of current board state
     */
    vector<vector<char>>& get_board_matrix();

    /**
     * @brief Applies a move to the board
     * @param move Move object containing the selected column
     * @return true if move was valid, false otherwise
     */
    bool update_board(Move<char>* move);

    /** @brief Checks if the player has won */
    bool is_win(Player<char>* player);

    /** @brief Checks if the player has lost */
    bool is_lose(Player<char>* player);

    /** @brief Checks if the game ended in a draw */
    bool is_draw(Player<char>* player);

    /** @brief Determines if the game is over (win/lose/draw) */
    bool game_is_over(Player<char>* player);

    // === AI Helper Functions ===

    /**
     * @brief Finds the next available row in a column
     * @param col Column index
     * @return Row index of next empty cell, or -1 if column full
     */
    int get_next_open_row(int col) const;

    /**
     * @brief Checks if a column is completely filled
     * @param col Column index
     * @return true if column is full, false otherwise
     */
    bool is_column_full(int col) const;

    /**
     * @brief Returns list of columns that still accept moves
     * @return Vector of valid column indices
     */
    vector<int> get_valid_columns() const;

    /**
     * @brief Drops a piece into a column for a given symbol
     * @param col Column index
     * @param sym Player symbol
     */
    void apply_move(int col, char sym);

    /**
     * @brief Removes a piece from a given cell (used in AI search)
     * @param row Row index
     * @param col Column index
     */
    void undo_move(int row, int col);
};

#endif
