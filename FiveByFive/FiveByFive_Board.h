#ifndef FIVEBYFIVE_BOARD_H
#define FIVEBYFIVE_BOARD_H

#include "BoardGame_Classes.h"
using namespace std;

class FiveByFive_Board : public Board<char> {
private:
    char blank = '.';
    bool check_three_in_row(char sym, int start_r, int start_c, int dir_r, int dir_c) const;

public:
    FiveByFive_Board();
    virtual ~FiveByFive_Board();

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_lose(Player<char>* player) override;
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
    int count_three_in_row(char sym) const;
    void display_board();
};

#endif