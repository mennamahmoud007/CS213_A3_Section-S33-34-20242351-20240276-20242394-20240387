/**
 * @file Misere_UI.h
 * @brief User Interface and AI logic for Misere Tic-Tac-Toe.
 */

#ifndef MISERE_UI_H
#define MISERE_UI_H

#include "BoardGame_Classes.h"
#include "Misere_Board.h"
using namespace std;

/**
 * @class Misere_UI
 * @brief Handles user input and AI decisions for Misere game mode.
 */
class Misere_UI : public UI<char> {
public:
    /**
     * @brief Constructor.
     */
    Misere_UI();

    /**
     * @brief Evaluates board for AI.
     */
    int evaluate(Misere_Board* mb, char aiSym);

    /**
     * @brief Minimax algorithm (no depth limit).
     */
    int minimax(Misere_Board* mb, char aiSym, char currentSym);

    /**
     * @brief Chooses best move for AI.
     */
    void choose_best_move(Misere_Board* mb, char aiSym, int& bestR, int& bestC);

    /**
     * @brief Creates a new player (Human or AI).
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Reads move input from player.
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Displays game rules.
     */
    void display_rules();
};

#endif
