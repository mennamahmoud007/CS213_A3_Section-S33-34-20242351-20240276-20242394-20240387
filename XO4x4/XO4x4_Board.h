#ifndef XO4X4_BOARD_H
#define XO4X4_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

class XO4x4_Board : public Board<char> {
private:
    char blank_symbol = '.';

    bool is_adjacent(int x1, int y1, int x2, int y2) const;
    bool check_three_in_row(char sym) const;

public:
    XO4x4_Board();
    virtual ~XO4x4_Board();

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
};

#endif


