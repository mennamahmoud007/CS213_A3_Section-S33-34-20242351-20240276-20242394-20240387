#ifndef ULTIMATE_BOARD_UI_H
#define ULTIMATE_BOARD_UI_H

#include "../Framework/BoardGame_Classes.h"
#include "Ultimate_Board.h"

class UltimateBoard_UI : public UI<char> {
public:
    UltimateBoard_UI() : UI<char>("Welcome to Ultimate Tic-Tac-Toe", 9) {}
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void display_rules() const;
    void display_ultimate_board(const UltimateBoard& board) const;
};

#endif