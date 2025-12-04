#ifndef ULTIMATE_UI_H
#define ULTIMATE_UI_H

#include "BoardGame_Classes.h"
#include "Ultimate_Board.h"
#include <string>

class Ultimate_UI : public UI<char> {
public:
    Ultimate_UI();
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void display_board_matrix(const vector<vector<char>>& matrix) const override {
        // Made it virtual in framework so it can be overridden in Ultimate_UI
    }

};

#endif 
