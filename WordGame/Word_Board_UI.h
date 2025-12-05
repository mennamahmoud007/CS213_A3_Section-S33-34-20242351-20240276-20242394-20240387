#ifndef WORD_Board_UI_H
#define WORD_Board_UI_H

#include "../Framework/BoardGame_Classes.h"
#include "Word_Board.h"

/**
 * @class WordUI
 * @brief UI handler for Word Tic-Tac-Toe (letter placement + word validation).
 */
class WordUI : public UI<char> {
public:
    /** Constructor */
    WordUI() : UI<char>("Welcome to Word Tic-Tac-Toe Game", 3) {}

    /**
     * @brief Evaluate the board score for the AI.
     * @return Positive score if AI is winning, negative if losing.
     */
    int evaluate_board(WordBoard* wb, char aiLetter);

    /**
     * @brief Minimax algorithm to compute best move.
     * @param currentLetter Letter of the player making the current move.
     */
    int minimax(WordBoard* wb, char aiLetter, char currentLetter);

    /**
     * @brief Compute the best possible move for the AI.
     * @param bestR Best row found.
     * @param bestC Best column found.
     */
    void choose_best_move(WordBoard* wb, char aiLetter, int& bestR, int& bestC);

    /**
     * @brief Create a human or AI player.
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Get next move from player (row, col, letter).
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Display rules for Word Tic-Tac-Toe.
     */
    void display_rules();
};

#endif
