#ifndef XO4X4_BOARD_H
#define XO4X4_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class XO4x4_Board
 * @brief 4x4 Tic-Tac-Toe variation where players move existing pieces as well.
 */
class XO4x4_Board : public Board<char> {
private:
    /** Symbol used for empty cells */
    char blank_symbol = '.';

    /**
     * @brief Check if two board positions are adjacent.
     * @param x1 First cell row.
     * @param y1 First cell column.
     * @param x2 Second cell row.
     * @param y2 Second cell column.
     * @return True if adjacent horizontally, vertically, or diagonally.
     */
    bool is_adjacent(int x1, int y1, int x2, int y2) const;

public:
    /** Constructor */
    XO4x4_Board();

    /** Destructor */
    virtual ~XO4x4_Board();

    /**
     * @brief Check if the symbol has 3 in a row (any direction).
     * @return True if the symbol wins.
     */
    bool check_three_in_row(char sym) const;

    /**
     * @brief Apply a player move (may be placement or movement).
     * @return True if move is valid and applied.
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Check if the player has 3 aligned symbols.
     */
    bool is_win(Player<char>* player) override;

    /** No losing condition for this variant */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Draw occurs when the board is full and no 3-in-row exists.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Game ends upon win or draw.
     */
    bool game_is_over(Player<char>* player) override;

    // =============================
    //       AI Helper Functions
    // =============================

    /** @return Cell content at (r, c) */
    char get_cell(int r, int c) const { return board[r][c]; }

    /**
     * @brief Apply simulated movement for AI.
     * @param x  Original row
     * @param y  Original column
     * @param nx New row
     * @param ny New column
     * @param sym Player symbol
     */
    void apply_move(int x, int y, int nx, int ny, char sym);

    /**
     * @brief Undo a previously applied move (AI use).
     */
    void undo_move(int x, int y, int nx, int ny, char sym);

    /**
     * @brief Get all legal moves for a player.
     * @return Vector of tuples: (x, y, nx, ny).
     */
    vector<tuple<int, int, int, int>> get_legal_moves(char sym) const;

    /** Next forced cell movement (for rule enforcement) */
    int next_nx = -1, next_ny = -1;
};

#endif
