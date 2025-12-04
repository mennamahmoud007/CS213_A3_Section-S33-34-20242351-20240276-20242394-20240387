#ifndef FOURINAROW_BOARD_H
#define FOURINAROW_BOARD_H

#include "BoardGame_Classes.h"
#include <vector>
#include <iostream>
using namespace std;

class FourInARow_Board : public Board<char> {
private:
    vector<vector<char>> board_matrix;
    const int rows = 6;
    const int cols = 7;
    const char blank = ' ';

    bool check_four_in_a_row(char symbol);

public:
    FourInARow_Board();
    ~FourInARow_Board();

    vector<vector<char>>& get_board_matrix();
    bool update_board(Move<char>* move);
    bool is_win(Player<char>* player);
    bool is_lose(Player<char>* player);
    bool is_draw(Player<char>* player);
    bool game_is_over(Player<char>* player);

    char get_cell(int r, int c) const { return board[r][c]; }
    void apply_move(int r, int c, char sym);
    void undo_move(int r, int c);
    vector<pair<int, int>> get_empty_cells() const;
};

#endif
