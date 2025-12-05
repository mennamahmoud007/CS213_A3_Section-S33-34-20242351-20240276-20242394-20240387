#include "Infinity_UI.h"
#include <iostream>
using namespace std;

Infinity_UI::Infinity_UI() : UI<char>("Welcome to Infinity Tic-Tac-Toe", 3) {}

Player<char>* Infinity_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer") << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* Infinity_UI::get_move(Player<char>* player) {
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
    }
    else {
        x = rand() % 3;
        y = rand() % 3;
    }

    return new Move<char>(x, y, player->get_symbol());
}
void Infinity_UI::display_rules() {
    cout << "\n=== INFINITY TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 3x3" << endl;
    cout << "2. Every 3 moves, the oldest mark disappears" << endl;
    cout << "3. Players place marks on empty cells" << endl;
    cout << "4. First to complete 3 in a row wins" << endl;
    cout << "=====================================" << endl;
}
