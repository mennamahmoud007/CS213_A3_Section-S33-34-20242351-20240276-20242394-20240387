#include "SUS_UI.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Player<char>* SUS_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "Human" : "Computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* SUS_UI::get_move(Player<char>* player) {
    int x, y;

    cout << player->get_name() << " (" << player->get_symbol() << ") enter your move (row col 0-2): ";
    cin >> x >> y;

    return new Move<char>(x, y, player->get_symbol());
}

char SUS_UI::get_player_symbol_choice(string player_name) {
    char c;
    cout << player_name << ", choose your letter (S or U): ";
    cin >> c;
    c = toupper(c);
    while (c != 'S' && c != 'U') {
        cout << "Invalid! Choose S or U: ";
        cin >> c;
        c = toupper(c);
    }
    return c;
}
