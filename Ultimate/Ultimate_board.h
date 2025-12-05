#ifndef ULTIMATE_BOARD_H
#define ULTIMATE_BOARD_H

#include "BoardGame_Classes.h"
#include <array>

/**
 * @class SubBoard
 * @brief Represents a 3x3 mini-board inside the Ultimate Tic Tac Toe game.
 *        Each sub-board works like a normal Tic Tac Toe board.
 */
class SubBoard : public Board<char> {
private:
    /** 3x3 local grid for the sub-board */
    std::array<std::array<char, 3>, 3> grid;

    /** Symbol used for empty cells */
    char blank = '.';

    /** Number of moves played in this sub-board */
    int moves_count;

public:
    /** Constructor */
    SubBoard();

    /**
     * @brief Apply a move inside this sub-board.
     * @param move Pointer to the move object.
     * @return True if move was applied, false otherwise.
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Check if the player has won this sub-board.
     * @param player Pointer to current player.
     * @return True if they have a winning line.
     */
    bool is_win(Player<char>* player) override;

    /** No losing condition in this board */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Check if the sub-board is full and no winner.
     * @return True if it is a draw.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Check if the sub-board is finished (win or draw).
     * @return True if the game is over.
     */
    bool game_is_over(Player<char>* player) override;

    /** @return True if cell (r, c) is empty. */
    bool cell_empty(int r, int c) const;

    /** @return The symbol stored in cell (r, c). */
    char get_cell(int r, int c) const;

    /**
     * @brief Check if this sub-board has been claimed (won by someone).
     * @return True if someone won it.
     */
    bool claimed() const;

    /**
     * @brief Get the winner of this sub-board.
     * @return Symbol of winner, or '.' if no winner.
     */
    char winner() const;

    /** Reset this sub-board to its initial state */
    void reset();
};

/**
 * @class UltimateBoard
 * @brief Controls the full 9-sub-board Ultimate Tic Tac Toe game.
 *        Players play in sub-boards determined by previous moves.
 */
class UltimateBoard : public Board<char> {
private:
    /** 3x3 grid of pointers to sub-boards */
    SubBoard* subs[3][3];

    /** Main grid showing which sub-board is won by which player */
    std::array<std::array<char, 3>, 3> mainGrid;

    /** Symbol for empty cells */
    char blank = '.';

    /** Total number of moves in the full game */
    int n_moves;

public:
    /** The required sub-board row for the next move (or -1 if free choice) */
    int next_subboard_row = -1;

    /** The required sub-board column for the next move (or -1 if free choice) */
    int next_subboard_col = -1;

    /** Constructor */
    UltimateBoard();

    /** Destructor */
    virtual ~UltimateBoard();

    /**
     * @brief Update the correct sub-board with the player's move.
     * @param move Pointer to the move object.
     * @return True if move applied successfully.
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Check if a player has won the entire Ultimate board.
     * @return True if the player won on the 3x3 main grid.
     */
    bool is_win(Player<char>* player) override;

    /**
     * @brief Check if the game is a draw.
     * @return True if all sub-boards are finished and no winner.
     */
    bool is_draw(Player<char>* player) override;

    /** No losing mechanic for this board */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Check if the whole game is over.
     * @return True if win or draw has occurred.
     */
    bool game_is_over(Player<char>* player) override;

    /**
     * @brief Synchronize the main board with the states of sub-boards.
     *        (Marked with winner symbol or '.')
     */
    void sync_base_board();

    /**
     * @brief Print the full Ultimate Tic Tac Toe board with all sub-boards.
     */
    void display_board();
};

#endif
