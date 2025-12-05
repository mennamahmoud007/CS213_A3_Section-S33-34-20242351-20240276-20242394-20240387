/**
 * @file Misere_Board.h
 * @brief Board logic for Misere Tic-Tac-Toe game mode.
 */

#ifndef MISERE_BOARD_H
#define MISERE_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class Misere_Board
 * @brief Implements Misere Tic-Tac-Toe rules where forming 3-in-a-row causes a loss.
 */
class Misere_Board : public Board<char> {
private:
    char blank = '.';               /**< Character representing an empty cell. */

    /**
     * @brief Checks if a symbol has formed 3 in a row.
     * @param sym The symbol to check.
     * @return true if symbol forms 3 in a row.
     */
    bool three_in_row(char sym) const;

public:
    /**
     * @brief Constructor initializes board.
     */
    Misere_Board();

    /**
     * @brief Destructor.
     */
    virtual ~Misere_Board();

    /**
     * @brief Updates the board with the player's move.
     * @param move Move made by a player.
     * @return true if move is valid.
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Checks if player has won (in Misere, win means opponent made 3-in-row).
     */
    bool is_win(Player<char>* player) override;

    /**
     * @brief Checks if player has lost (player forms 3-in-row).
     */
    bool is_lose(Player<char>* player) override;

    /**
     * @brief Checks if game ended in a draw.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Checks if game is finished.
     */
    bool game_is_over(Player<char>* player) override;

    /**
     * @brief Gets value of a cell.
     */
    char get_cell(int r, int c) const { return board[r][c]; }

    /**
     * @brief Places a symbol on the board.
     */
    void apply_move(int r, int c, char sym);

    /**
     * @brief Removes a symbol from the board.
     */
    void undo_move(int r, int c);
};

#endif
