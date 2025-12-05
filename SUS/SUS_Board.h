#ifndef SUS_BOARD_H
#define SUS_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class SUS_Board
 * @brief Board class for the SUS game.
 *        Players place 'S' or 'U' on the board, and the goal is to form "SUS" sequences.
 */
class SUS_Board : public Board<char> {
private:
    /** Symbol used for empty cells */
    char blank_symbol = '.';

public:
    /** Constructor */
    SUS_Board();

    /** Destructor */
    virtual ~SUS_Board();

    /**
     * @brief Apply a move to the board if the cell is empty.
     * @param move Pointer to the move object.
     * @return True if the move is valid and applied, false otherwise.
     */
    bool update_board(Move<char>* move) override;

    /** @return Always false – SUS game has no standard win condition. */
    bool is_win(Player<char>* player) override { return false; }

    /** @return Always false – SUS game has no lose condition. */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Check if the game is a draw (board full).
     * @return True if no moves left, false otherwise.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Check if the game is over (draw only).
     * @return True if board is full.
     */
    bool game_is_over(Player<char>* player) override;

    /**
     * @brief Count how many "SUS" sequences appear after placing at (r, c).
     * @param r Row index.
     * @param c Column index.
     * @return Number of SUS sequences found.
     */
    int count_SUS_sequences(int r, int c);

    /** Score for player using 'S' */
    int score_S = 0;

    /** Score for player using 'U' */
    int score_U = 0;

    /** @return The symbol in cell (r, c). */
    char get_cell(int r, int c) const { return board[r][c]; }

    /** @return True if the cell is empty. */
    bool is_empty(int r, int c) const { return board[r][c] == blank_symbol; }

    /**
     * @brief Apply a simulated move (used by minimax).
     * @param r Row index.
     * @param c Column index.
     * @param sym Symbol to place.
     */
    void apply_move(int r, int c, char sym);

    /**
     * @brief Undo a simulated move and reset cell to empty.
     * @param r Row index.
     * @param c Column index.
     */
    void undo_move(int r, int c);

    /**
     * @brief Get a list of all empty cells on the board.
     * @return Vector of (row, column) pairs.
     */
    vector<pair<int, int>> get_empty_cells() const;

    /**
     * @brief Count all SUS sequences across the entire board.
     * @return Total number of SUS patterns.
     */
    int count_all_SUS_sequences() const;
};

#endif
