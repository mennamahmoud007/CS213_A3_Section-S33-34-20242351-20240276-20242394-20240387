#ifndef XO4X4_BOARD_H
#define XO4X4_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

class XO4x4_Board : public Board<char> {
private:
    char blank_symbol = '.';

    bool is_adjacent(int x1, int y1, int x2, int y2) const;
    

public:
    XO4x4_Board();
    virtual ~XO4x4_Board();

    bool check_three_in_row(char sym) const;
    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;

    // Functions for AI
    char get_cell(int r, int c) const { return board[r][c]; }
    void apply_move(int x, int y, int nx, int ny, char sym);
    void undo_move(int x, int y, int nx, int ny, char sym);
    vector<tuple<int, int, int, int>> get_legal_moves(char sym) const;

    int next_nx = -1;
    int next_ny = -1;
};

#endif


