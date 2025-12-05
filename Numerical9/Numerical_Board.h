/**
 * @file Numeric_Board.h
 * @brief Header file for the NumericBoard class (Numerical Tic-Tac-Toe).
 */

#ifndef NUMERICAL_BOARD_H
#define NUMERICAL_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
#include <utility>
using namespace std;

/**
 * @class NumericBoard
 * @brief Represents the board for the Numerical Tic-Tac-Toe game.
 *
 * - Player X uses odd numbers (1,3,5,7,9)
 * - Player O uses even numbers (0,2,4,6,8)
 * - A player wins if any row, column, or diagonal sums to 15
 */
class NumericBoard : public Board<int> {
private:
    bool x_out_of_moves = false;       ///< True if X has no available numbers left.
    bool o_out_of_moves = false;       ///< True if O has no available numbers left.
    int even_used = 0, odd_used = 0;   ///< Counts how many even/odd numbers have been used.
    int blank_symbol = 0;              ///< Represents an empty cell.
    bool usedNum[10];                  ///< Tracks which numbers have already been used.

    /**
     * @brief Checks if three numbers form a winning line (sum = 15).
     * @param a First number
     * @param b Second number
     * @param c Third number
     * @return true if a + b + c == 15
     */
    bool line_is_win(int a, int b, int c) const;

public:

    /**
     * @brief Constructor: initializes the board and resets used numbers.
     */
    NumericBoard();

    /**
     * @brief Destructor.
     */
    virtual ~NumericBoard() {}

    /**
     * @brief Applies a player's move to the board.
     * @param move Pointer to Move<int> containing row, column, and the number.
     * @return true if the move is successfully applied.
     */
    bool update_board(Move<int>* move) override;

    /**
     * @brief Checks if the given player has won.
     */
    bool is_win(Player<int>* player) override;

    /**
     * @brief Checks if the given player has lost.
     */
    bool is_lose(Player<int>* player) override;

    /**
     * @brief Checks if the game ended in a draw.
     */
    bool is_draw(Player<int>* player) override;

    /**
     * @brief Determines whether the game is over (win/lose/draw).
     */
    bool game_is_over(Player<int>* player) override;

    /**
     * @brief Returns the list of available numbers for the current player.
     * @param unused If true, returns numbers that have not been used yet.
     */
    vector<int> available_nums(bool unused = false) const;

    /**
     * @brief Returns all empty cells on the board.
     */
    vector<pair<int, int>> available_cells() const;

    /**
     * @brief Gets the value stored in a specific cell.
     */
    int get_cell(int r, int c) const {
        return board[r][c];
    }

    /**
     * @brief Returns the positions forming the winning line.
     */
    vector<pair<int, int>> get_winning_positions() const;
};

#endif 
