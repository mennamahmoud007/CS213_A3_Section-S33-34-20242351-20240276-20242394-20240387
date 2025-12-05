#ifndef FIVEBYFIVE_BOARD_H
#define FIVEBYFIVE_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

/**
 * @class FiveByFive_Board
 * @brief Represents a 5x5 Tic-Tac-Toe board.
 *
 * Inherits from Board<char>. Handles game logic specific to 5x5 Tic-Tac-Toe,
 * including checking for 3-in-a-row sequences, wins, losses, draws, and board updates.
 */
class FiveByFive_Board : public Board<char> {
private:
    char blank = '.';  /**< Symbol for empty cell */

    /**
     * @brief Checks for a 3-in-a-row starting from a specific cell in a specific direction
     * @param sym Player's symbol
     * @param start_r Starting row
     * @param start_c Starting column
     * @param dir_r Row direction (-1,0,1)
     * @param dir_c Column direction (-1,0,1)
     * @return true if 3-in-a-row found, false otherwise
     */
    bool check_three_in_row(char sym, int start_r, int start_c, int dir_r, int dir_c) const;

public:
    /** @brief Constructor: initializes the 5x5 board */
    FiveByFive_Board();

    /** @brief Destructor */
    virtual ~FiveByFive_Board();

    /**
     * @brief Applies a move to the board
     * @param move Pointer to the Move object
     * @return true if move applied successfully, false otherwise
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
     * @brief Checks if the game is a draw
     * @param player Pointer to the Player object
     * @return true if draw, false otherwise
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Checks if the game is over
     * @param player Pointer to the Player object
     * @return true if game over, false otherwise
     */
    bool game_is_over(Player<char>* player) override;

    /**
     * @brief Counts the number of 3-in-a-row sequences for a symbol
     * @param sym Player's symbol
     * @return Number of 3-in-a-row sequences
     */
    int count_three_in_row(char sym) const;

    /** @brief Displays the board */
    void display_board();

    /** @brief Gets the symbol at a specific cell */
    char get_cell(int r, int c) const { return board[r][c]; }

    /** @brief Applies a move at row r and column c for the given symbol */
    void apply_move(int r, int c, char sym);

    /** @brief Undoes a move at row r and column c */
    void undo_move(int r, int c);

    /** @brief Returns a vector of empty cell coordinates */
    vector<pair<int, int>> get_empty_cells() const;
};

#endif
