#ifndef SUS_UI_H
#define SUS_UI_H

#include "BoardGame_Classes.h"
#include "SUS_Board.h"

class SUS_UI : public UI<char> {
private:
    static int p;
public:
    SUS_UI();

    int evaluate_board(SUS_Board* sb, char aiSym);
    int minimax(SUS_Board* sb, char aiSym, char currentSym);
    void choose_best_move(SUS_Board* sb, char aiSym, int& bestR, int& bestC);
    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;


    //void print_game_result(SUS_Board& board);
};

#endif