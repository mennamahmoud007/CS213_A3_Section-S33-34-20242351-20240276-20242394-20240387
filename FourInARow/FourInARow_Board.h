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

public:
    FourInARow_Board();
    ~FourInARow_Board();

    bool check_four_in_a_row(char symbol);
    vector<vector<char>>& get_board_matrix();
    bool update_board(Move<char>* move);
    bool is_win(Player<char>* player);
    bool is_lose(Player<char>* player);
    bool is_draw(Player<char>* player);
    bool game_is_over(Player<char>* player);

    int get_next_open_row(int col) const;
    bool is_column_full(int col) const;
    vector<int> get_valid_columns() const;
    void apply_move(int col, char sym);
    void undo_move(int row, int col);
};

#endif
