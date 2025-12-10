#ifndef WORD_Board_UI_H
#define WORD_Board_UI_H

#include "../Framework/BoardGame_Classes.h"
#include "Word_Board.h"

/**
 * @class WordUI
 * @brief UI for Word Tic-Tac-Toe game
 */
class WordUI : public UI<char> {
public:
    WordUI() : UI<char>("Welcome to Word Tic-Tac-Toe Game", 3) {}

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void display_rules();

private:
    /// @brief Smart AI strategy for computer player
    Move<char>* get_smart_ai_move(WordBoard* board);

};

#endif