#include "Diamond_UI.h"
#include <iostream>

using namespace std;

Diamond_UI::Diamond_UI() : UI<char>("Welcome to Diamond Tic-Tac-Toe", 9) {}

Player<char>* Diamond_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* Diamond_UI::get_move(Player<char>* player) {
    int x, y;
    if (player->get_type() == PlayerType::HUMAN) {
        cout << "Enter row and column (0..8) for your move: ";
        cin >> x >> y;
    }
    else {
        x = rand() % 9;
        y = rand() % 9;
    }
    return new Move<char>(x, y, player->get_symbol());
}
