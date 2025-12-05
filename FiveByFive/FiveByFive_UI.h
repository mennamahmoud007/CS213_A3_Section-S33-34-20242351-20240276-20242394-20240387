#ifndef FIVEBYFIVE_UI_H
#define FIVEBYFIVE_UI_H

#include "BoardGame_Classes.h"
#include "FiveByFive_Board.h"
using namespace std;

/**
 * @class FiveByFive_UI
 * @brief Handles user interface and AI for 5x5 Tic-Tac-Toe.
 *
 * Inherits from UI<char>. Manages input/output, AI decision-making (minimax),
 * and displays rules for 5x5 Tic-Tac-Toe.
 */
class FiveByFive_UI : public UI<char> {
public:
    /** @brief Constructor */
    FiveByFive_UI();

    /**
     * @brief Evaluates the board from AI perspective
     * @param fb Pointer to FiveByFive_Board
     * @param aiSym Symbol of AI player
     * @return Score of the board
     */
    int evaluate_board(FiveByFive_Board* fb, char aiSym);

    /**
     * @brief Minimax algorithm for AI decision making
     * @param fb Pointer to FiveByFive_Board
     * @param aiSym Symbol of AI
     * @param currentSym Symbol of current player
     * @param depth Current recursion depth
     * @param maxDepth Maximum depth
     * @return Best score for current player
     */
    int minimax(FiveByFive_Board* fb, char aiSym, char currentSym, int depth, int maxDepth);

    /**
     * @brief Determines the best move for AI
     * @param fb Pointer to FiveByFive_Board
     * @param aiSym Symbol of AI
     * @param bestR Reference to store best row
     * @param bestC Reference to store best column
     */
    void choose_best_move(FiveByFive_Board* fb, char aiSym, int& bestR, int& bestC);

    /**
     * @brief Creates a player (human or AI)
     * @param name Name of the player
     * @param symbol Symbol used by the player
     * @param type PlayerType (Human or AI)
     * @return Pointer to Player object
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Prompts player for a move
     * @param player Pointer to Player object
     * @return Pointer to Move object chosen by player
     */
    Move<char>* get_move(Player<char>* player) override;

    /** @brief Displays the game rules for 5x5 Tic-Tac-Toe */
    void display_rules();
};

#endif
