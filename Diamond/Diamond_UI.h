#ifndef DIAMOND_UI_H
#define DIAMOND_UI_H

#include "BoardGame_Classes.h"
#include "Diamond_Board.h"
using namespace std;

/**
 * @class Diamond_UI
 * @brief Handles user interface and AI for Diamond Tic-Tac-Toe.
 *
 * Inherits from UI<char>. Manages input/output, AI decision-making (minimax),
 * and game rules display for the Diamond Tic-Tac-Toe variant.
 */
class Diamond_UI : public UI<char> {
public:
    /** @brief Constructor */
    Diamond_UI();

    /**
     * @brief Evaluates the board from AI perspective
     * @param db Pointer to Diamond_Board
     * @param aiSym Symbol of the AI player
     * @return Score of the board
     */
    int evaluate_board(Diamond_Board* db, char aiSym);

    /**
     * @brief Minimax algorithm for AI decision making
     * @param db Pointer to Diamond_Board
     * @param aiSym Symbol of AI
     * @param currentSym Symbol of current player
     * @param depth Current depth of recursion
     * @param maxDepth Maximum depth for minimax
     * @return Best score for current player
     */
    int minimax(Diamond_Board* db, char aiSym, char currentSym, int depth, int maxDepth);

    /**
     * @brief Determines the best move for AI
     * @param db Pointer to Diamond_Board
     * @param aiSym Symbol of AI
     * @param bestR Reference to store best row
     * @param bestC Reference to store best column
     */
    void choose_best_move(Diamond_Board* db, char aiSym, int& bestR, int& bestC);

    /**
     * @brief Creates a player (human or AI)
     * @param name Name of the player
     * @param symbol Symbol used by the player
     * @param type PlayerType (Human or AI)
     * @return Pointer to the created Player object
     */
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;

    /**
     * @brief Prompts player for a move
     * @param player Pointer to the Player object
     * @return Pointer to Move object chosen by player
     */
    Move<char>* get_move(Player<char>* player) override;

    /** @brief Displays the game rules for Diamond Tic-Tac-Toe */
    void display_rules();
};

#endif