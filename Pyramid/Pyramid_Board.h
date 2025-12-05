/**
 * @file Pyramid_Board.h
 * @brief Header file for the Pyramid_Board class.
 *
 * This board represents a pyramid-shaped version of Tic-Tac-Toe,
 * where some cells are blocked and only specific triangular win patterns exist.
 */

#ifndef PYRAMID_BOARD_H
#define PYRAMID_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
using namespace std;

/**
 * @class Pyramid_Board
 * @brief Implements the rules and mechanics of the Pyramid Tic-Tac-Toe game.
 *
 * - Board includes blocked cells (#) that players cannot use.
 * - Winning patterns follow the pyramid shape.
 * - Supports AI evaluation through helper functions like apply/undo moves.
 */
class Pyramid_Board : public Board<char> {
private:
    char blocked_symbol = '#';   ///< Symbol used to mark blocked (unusable) cells.

    /**
     * @brief Stores all valid winning line combinations for the pyramid layout.
     * Each line is a vector of cell coordinates.
     */
    vector<vector<pair<int, int>>> winLines;

public:

    /**
     * @brief Constructs the pyramid board and initializes win patterns.
     */
    Pyramid_Board();

    /**
     * @brief Destructor.
     */
    virtual ~Pyramid_Board();

    /**
     * @brief Applies a player's move to the board.
     * @param move Pointer to the player's move
     * @return true if the move is valid and executed
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Checks whether the player achieved a winning pyramid line.
     */
    bool is_win(Player<char>* player) override;

    /**
     * @brief There is no lose state specific to this version (always false).
     */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Checks if the board has no available moves.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Determines whether the game should end.
     */
    bool game_is_over(Player<char>* player) override;

    // =========================
    //  AI Support Functions
    // =========================

    /**
     * @brief Returns all possible win line coordinate sets.
     */
    vector<vector<pair<int, int>>> get_win_lines() const { return winLines; }

    /**
     * @brief Retrieves the symbol at a given cell.
     */
    char get_cell(int r, int c) const { return board[r][c]; }

    /**
     * @brief Simulates placing a symbol on the board (for AI).
     */
    void apply_move(int r, int c, char sym);

    /**
     * @brief Removes a simulated symbol (undoing AI move).
     */
    void undo_move(int r, int c);

    /**
     * @brief Returns a list of all empty and available cells.
     */
    vector<pair<int, int>> get_empty_cells() const;

    /**
     * @brief Checks whether a symbol currently forms a win on the board.
     * Useful for AI evaluation.
     */
    bool is_win_for_symbol(char sym);
};

#endif
