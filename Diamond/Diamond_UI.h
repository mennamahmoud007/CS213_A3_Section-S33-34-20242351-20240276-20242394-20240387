#ifndef DIAMOND_UI_H
#define DIAMOND_UI_H

#include "BoardGame_Classes.h"
#include "Diamond_Board.h"
using namespace std;

class Diamond_UI : public UI<char> {
public:
    Diamond_UI();

    int evaluate_board(Diamond_Board* db, char aiSym);
    int minimax(Diamond_Board* db, char aiSym, char currentSym, int depth, int maxDepth);
    void choose_best_move(Diamond_Board* db, char aiSym, int& bestR, int& bestC);

    Player<char>* create_player(string& name, char symbol, PlayerType type) override;
    Move<char>* get_move(Player<char>* player) override;
    void display_rules();
};

#endif 
