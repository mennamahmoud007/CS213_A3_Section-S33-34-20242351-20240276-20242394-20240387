#pragma once
#include "BoardGame_Classes.h"
#include "SUS_Board.h"
#include <iostream>

class SUS_UI : public UI<char> {
public:
    SUS_UI();
    Player<char>* create_player(std::string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
};
