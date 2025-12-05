#ifndef MISERE_UI_H
#define MISERE_UI_H

#include "BoardGame_Classes.h"
#include "Misere_Board.h"
using namespace std;

class Misere_UI : public UI<char> {
public:
    Misere_UI();
    int evaluate(Misere_Board* mb, char aiSym);
    int minimax(Misere_Board* mb, char aiSym, char currentSym);
    void choose_best_move(Misere_Board* mb, char aiSym, int& bestR, int& bestC);

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void display_rules();
};

#endif
