#pragma once
#include "BoardGame_Classes.h"
#include <cctype>

class SUS_Board : public Board<char> {
public:
    SUS_Board();

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override;
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;
};
