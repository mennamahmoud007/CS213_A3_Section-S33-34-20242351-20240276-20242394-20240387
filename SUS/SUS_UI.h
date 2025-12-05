#ifndef SUS_UI_H
#define SUS_UI_H

#include "BoardGame_Classes.h"
#include "SUS_Board.h"

/**
 * @class SUS_UI
 * @brief Handles user interaction and AI logic for the SUS game.
 */
class SUS_UI : public UI<char> {
private:
    /** Static variable for internal tracking. */
    static int p;

public:
    /** Constructor */
    SUS_UI();

    /**
     * @brief Evaluate the board for minimax scoring.
     * @param sb Pointer to SUS board.
     * @param aiSym AI player symbol.
     * @return Score value for the board state.
     */
    int evaluate_board(SUS_Board* sb, char aiSym);

    /**
     * @brief Minimax algorithm for the SUS AI.
     * @param sb Pointer to SUS board.
     * @param aiSym AI player symbol.
     * @param currentSym Symbol of current turn.
     * @return Evaluation score.
     */
    int minimax(SUS_Board* sb, char aiSym, char currentSym);

    /**
     * @brief Find the best move for the AI using minimax.
     * @param sb Pointer to SUS board.
     * @param aiSym AI player symbol.
     * @param bestR Output row for best move.
     * @param bestC Output column for best move.
     */
    void choose_best_move(SUS_Board* sb, char aiSym, int& bestR, int& bestC);

    /**
     * @brief Create a new player object for the game.
     * @param name Player name.
     * @param symbol Player symbol ('S' or 'U').
     * @param type Human or AI.
     * @return Pointer to newly created player.
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Get player move (row and column input).
     * @param player Pointer to current player.
     * @return Pointer to move object.
     */
    Move<char>* get_move(Player<char>* player) override;

    /**
     * @brief Display the game rules to the player.
     */
    void display_rules();
};

#endif
