#pragma once
#include "BoardGame_Classes.h"
#include <string>
#include <iostream>
using namespace std;

class SUS_UI : public UI<char> {
public:
    SUS_UI() : UI<char>("Welcome to SUS Game", 3) {}

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    char get_player_symbol_choice(string player_name);
};
