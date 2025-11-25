#ifndef NUMERICAL_UI_H
#define NUMERICAL_UI_H

#include "BoardGame_Classes.h"
#include "Numerical_Board.h"
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class NumericalUI : public UI<int> {
public:
    NumericalUI() : UI<int>("Welcome to our Numerical Game", 3) {}

    //void display_board_matrix(const vector<vector<char>>& matrix) const;
    Player<int>* create_player(string& name, int symbol, PlayerType type) override;
    Move<int>* get_move(Player<int>* player) override;
    //void print_game_result(NumericBoard& board);
};

#endif
