#ifndef ULTIMATE_BOARD_H
#define ULTIMATE_BOARD_H

#include "BoardGame_Classes.h"
#include <array>

class SubBoard : public Board<char> {
private:
    std::array<std::array<char, 3>, 3> grid;
    char blank = '.';
    int moves_count;

public:
    SubBoard();
    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;

    bool cell_empty(int r, int c) const;
    char get_cell(int r, int c) const;
    bool claimed() const;
    char winner() const;
    void reset();
};

class UltimateBoard : public Board<char> {
private:
    SubBoard* subs[3][3];
    std::array<std::array<char, 3>, 3> mainGrid;
    char blank = '.';
    int n_moves;

public:
    int next_subboard_row = -1; 
    int next_subboard_col = -1;

    UltimateBoard();
    virtual ~UltimateBoard();

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_draw(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }

    bool game_is_over(Player<char>* player) override;

    void sync_base_board();
    void display_board();
};

#endif
