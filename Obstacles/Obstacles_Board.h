/**
 * @file Obstacles_Board.h
 * @brief Header file for the ObstaclesBoard class.
 *
 * This variant of Tic-Tac-Toe introduces obstacles that appear on the board
 * every few moves, making the game progressively harder.
 */

#ifndef OBSTACLES_BOARD_H
#define OBSTACLES_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
#include <utility>

using namespace std;

/**
 * @class ObstaclesBoard
 * @brief Represents the board for the Obstacles Tic-Tac-Toe game.
 *
 * - Players place symbols as usual.
 * - After a certain number of moves, obstacles ('#') appear on the board.
 * - Obstacles block both players and cannot be replaced.
 */
class ObstaclesBoard : public Board<char> {
private:
    char blank_symbol = '.';  ///< Symbol representing an empty cell.
    char obstacle = '#';      ///< Symbol representing an obstacle.
    int moves_round = 0;      ///< Counter to track when to add new obstacles.

    /**
     * @brief Checks if the given symbol has four in a row.
     * @param sym Player symbol ('X' or 'O')
     * @return true if a winning line is found
     */
    bool check_4_in_row(char sym) const;

    /**
     * @brief Adds a given number of obstacles at random empty locations.
     * @param count Number of obstacles to add
     */
    void add_obstacle(int count);

public:
    /**
     * @brief Constructor: initializes the board.
     */
    ObstaclesBoard();

    /**
     * @brief Destructor.
     */
    virtual ~ObstaclesBoard();

    /**
     * @brief Applies a player's move to the board.
     * Also triggers obstacle placement every few rounds.
     * @param move Player move pointer
     * @return true if the move is valid and applied
     */
    bool update_board(Move<char>* move) override;

    /**
     * @brief Checks if the player has won the game.
     */
    bool is_win(Player<char>* player) override;

    /**
     * @brief Obstacles game has no “lose” condition, always returns false.
     */
    bool is_lose(Player<char>* player) override { return false; }

    /**
     * @brief Determines if the board is full or no moves remain.
     */
    bool is_draw(Player<char>* player) override;

    /**
     * @brief Checks whether the game should end.
     */
    bool game_is_over(Player<char>* player) override;
};

#endif
