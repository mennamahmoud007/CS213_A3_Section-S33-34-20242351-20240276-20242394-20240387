#ifndef SUS_UI_H
#define SUS_UI_H

#include "BoardGame_Classes.h"
#include "SUS_Board.h"

class SUS_UI : public UI<char> {
public:
    SUS_UI();
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void print_game_result(SUS_Board& board);
};

#endif