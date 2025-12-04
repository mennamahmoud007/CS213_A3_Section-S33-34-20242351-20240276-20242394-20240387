#ifndef FOURINAROW_UI_H
#define FOURINAROW_UI_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <string>
#include <cstdlib> // for rand()
using namespace std;

class FourInARow_UI : public UI<char> {
public:
    FourInARow_UI();

    int evaluate(FourInARow_Board* fb, char aiSym);
    int minimax(FourInARow_Board* fb, int depth, bool maximizing, char aiSym);
    void choose_best_move(FourInARow_Board* fb, char aiSym, int& bestCol);

    Player<char>* create_player(string& name, char symbol, PlayerType type);
    Move<char>* get_move(Player<char>* player);

    void display_board_matrix(const vector<vector<char>>& matrix);
    void display_message(const string& message);
};

#endif
