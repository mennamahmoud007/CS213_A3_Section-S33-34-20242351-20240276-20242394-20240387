#ifndef FIVEBYFIVE_UI_H
#define FIVEBYFIVE_UI_H

#include "BoardGame_Classes.h"
#include "FiveByFive_Board.h"
using namespace std;

class FiveByFive_UI : public UI<char> {
public:
    FiveByFive_UI();
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
};

#endif