#ifndef INFINITY_BOARD_H
#define INFINITY_BOARD_H

#include "BoardGame_Classes.h"
#include <queue>
using namespace std;

/**
 * @class Infinity_Board
 * @brief Special Tic-Tac-Toe variant where the board never fills.
 *
 * In this mode, each player keeps placing symbols. After every 3 moves,
 * the oldest placed symbol gets removed automatically. This creates
 * an "infinite" gameplay loop where the board keeps changing.
 *
 * The class tracks moves using a queue and checks win conditions
 * based on the current board state.
 */
class Infinity_Board : public Board<char> {
private:
    char blank = '.';   /**< Symbol used for empty cells */
    queue<pair<int, int>> moves; /**< Stores positions of moves in order to remove the oldest */

    /**
     * @brief Checks if the given symbol has 3 consecutive cells in a row/col/diagonal.
     * @param sym Symbol to check ('X' or 'O')
     * @return true if 3 in a row exists, false otherwise
     */
    bool three_in_row(char sym) const;

public:
    /** @brief Constructor: initializes an empty Infinity board */
    Infinity_Board();

    /** @brief Destructor */
    virtual ~Infinity_Board();

    /**
     * @brief Applies a move to the board.
     * @param move Move object containing row/column positions
     * @return true if move was valid, false otherwise
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Removes the oldest placed symbol.
     *
     * Triggered automatically after every 3 moves.
     */
    void remove_oldest();

    /** @brief Checks if the player has won */
    bool is_win(Player<char>* player) override;

    /** @brief Checks if the player has lost */
    bool is_lose(Player<char>* player) override;

    /**
     * @brief Infinity mode cannot draw because pieces get removed forever.
     * @return Always false
     */
    bool is_draw(Player<char>* player) override;

    /** @brief Checks if the game is over (win/lose) */
    bool game_is_over(Player<char>* player) override;

    /** @brief Displays the current board */
    void display_board();
};

#endif
