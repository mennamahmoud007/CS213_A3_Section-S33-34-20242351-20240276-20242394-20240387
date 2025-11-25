#pragma once
#include "BoardGame_Classes.h"
#include <string>

class SUS_UI : public UI<char> {
public:
    SUS_UI() : UI<char>("Welcome to SUS Game!", 3) {}

    Player<char>* create_player(std::string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    char get_player_symbol_choice(std::string player_name);
};
