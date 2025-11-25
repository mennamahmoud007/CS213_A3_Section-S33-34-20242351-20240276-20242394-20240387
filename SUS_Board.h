#pragma once
#include "BoardGame_Classes.h"
#include <vector>
#include <iostream>
using namespace std;

class SUS_Board : public Board<char> {
private:
    int p1_score = 0;
    int p2_score = 0;

public:
    SUS_Board();

    
    bool update_board(Move<char>* move, Player<char>* player);

    bool update_board(Move<char>* move) override;
    bool is_win(Player<char>* player) override { return false; }  // لا يوجد فائز قبل امتلاء اللوحة
    bool is_lose(Player<char>* player) override { return false; }
    bool is_draw(Player<char>* player) override;
    bool game_is_over(Player<char>* player) override;

    int count_sus_sequences();

    int get_score(Player<char>* player);
};
