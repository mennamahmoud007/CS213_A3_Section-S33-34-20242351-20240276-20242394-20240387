#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "BoardGame_Classes.h"

class SUS_UI {
public:
    SUS_UI(bool fixedLetterMode_ = false);

    // Match this to the CPP
    void display_board_matrix(const std::vector<std::vector<char>>& matrix);

    void display_message(const std::string& msg);
    void ask_players_for_letters(Player<char>* p1, Player<char>* p2);
    Move<char>* get_move(Player<char>* p);

private:
    bool fixedLetterMode;
    char playerLetterMap[2];
};
