#include "XO4x4_UI.h"
#include <iostream>
using namespace std;

XO4x4_UI::XO4x4_UI() : UI<char>("Welcome to 4x4 Moving XO Game", 3) {}

Player<char>* XO4x4_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* XO4x4_UI::get_move(Player<char>* player) {
    /*int x, y;*/

    int x, y, nx, ny;
    Board<char>* b = player->get_board_ptr();
    XO4x4_Board* xb = static_cast<XO4x4_Board*>(b);


    if (player->get_type() == PlayerType::HUMAN) {
        
        cout << "\nEnter the position of the token you want to move (row(0-3) , col(0-3)): ";
        cin >> x >> y;

        cout << "Enter the new position (row(0-3) , col(0-3)): ";
        cin >> nx >> ny;

    }
    else {

        x = rand() % b->get_rows();
        y = rand() % b->get_columns();

        
        nx = rand() % b->get_rows();
        ny = rand() % b->get_columns();
    }

    xb->next_nx = nx;
    xb->next_ny = ny;

    return new Move<char>(x, y, player->get_symbol());
}