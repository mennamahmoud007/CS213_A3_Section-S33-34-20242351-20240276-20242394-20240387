#ifndef XO4x4_UI_H
#define XO4x4_UI_H

#include "BoardGame_Classes.h"
#include "XO4x4_Board.h"

class XO4x4_UI : public UI<char> {
public:
    XO4x4_UI();
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void display_rules();
};

#endif