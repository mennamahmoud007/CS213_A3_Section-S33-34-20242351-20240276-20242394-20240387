#ifndef FOURINAROW_UI_H
#define FOURINAROW_UI_H

#include "BoardGame_Classes.h"
#include "FourInARow_Board.h"
using namespace std;

/**
 * @class FourInARow_UI
 * @brief Handles all input/output and AI decision-making for Connect 4.
 *
 * Displays the board, interacts with players, shows rules,
 * and contains a simple AI that chooses the best column.
 */
class FourInARow_UI : public UI<char> {
public:
    /** @brief Constructor */
    FourInARow_UI();

    /**
     * @brief Chooses the best column for the AI to play
     * @param fb Pointer to the game board
     * @param aiSym Symbol of AI player
     * @return Index of best column
     */
    int choose_best_column(FourInARow_Board* fb, char aiSym);

    /**
     * @brief Creates a new player (Human or AI)
     * @param name Player name
     * @param symbol Symbol used by the player
     * @param type PlayerType enum
     * @return Pointer to a Player object
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type);

    /**
     * @brief Gets a player's move input
     * @param player Pointer to player
     * @return Pointer to a Move object
     */
    Move<char>* get_move(Player<char>* player);

    /** @brief Displays the rules of Connect 4 */
    void display_rules();

    /**
     * @brief Prints the game board to the console
     * @param matrix 2D board matrix
     */
    void display_board_matrix(const vector<vector<char>>& matrix);

    /**
     * @brief Displays a message on screen
     * @param message String to print
     */
    void display_message(const string& message);
};

#endif
