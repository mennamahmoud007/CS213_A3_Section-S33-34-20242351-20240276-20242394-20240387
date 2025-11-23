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
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nEnter the position of the token you want to move (row(0-3) , col(0-3)): ";
        cin >> x >> y;
    }
    else {
        Board<char>* b = player->get_board_ptr();
        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}