#ifndef NUMERICAL_BOARD_H
#define NUMERICAL_BOARD_H

#include "BoardGame_Classes.h"
#include "Numerical_Player.h"
#include <vector>
#include <utility>

using namespace std;

class NumericBoard : public Board<int> {
private:
    char blank_symbol = '.';
    bool usedNum[10];
    bool line_is_win(int a, int b, int c) const;

public:
    NumericBoard();
    virtual ~NumericBoard() {}

    bool update_board(Move<int>* move) override;
    bool is_win(Player<int>* player) override;
    bool is_lose(Player<int>* player) override { return false; }
    bool is_draw(Player<int>* player) override;
    bool game_is_over(Player<int>* player) override;

    vector<int> available_nums(bool unused = false) const;
    vector<pair<int, int>> available_cells() const;

    int get_cell(int r, int c) const { return board[r][c]; }
    vector<pair<int, int>> get_winning_positions() const;
};

#endif
