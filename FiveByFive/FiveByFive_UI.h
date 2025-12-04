#ifndef FIVEBYFIVE_UI_H
#define FIVEBYFIVE_UI_H

#include "BoardGame_Classes.h"
#include "FiveByFive_Board.h"
using namespace std;

class FiveByFive_UI : public UI<char> {
public:
    FiveByFive_UI();

    int evaluate_board(FiveByFive_Board* fb, char aiSym);
    int minimax(FiveByFive_Board* fb, char aiSym, char currentSym, int depth, int maxDepth);
    void choose_best_move(FiveByFive_Board* fb, char aiSym, int& bestR, int& bestC);

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
};

#endif