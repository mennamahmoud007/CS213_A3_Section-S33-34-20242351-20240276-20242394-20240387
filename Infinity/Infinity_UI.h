#ifndef INFINITY_UI_H
#define INFINITY_UI_H

#include "BoardGame_Classes.h"
#include "Infinity_Board.h"
using namespace std;

class Infinity_UI : public UI<char> {
public:
    Infinity_UI();
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
};

#endif
