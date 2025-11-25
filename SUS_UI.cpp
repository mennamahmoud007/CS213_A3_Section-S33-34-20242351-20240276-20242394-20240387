#include "SUS_UI.h"
#include <cstdlib>
using namespace std;

SUS_UI::SUS_UI()
    : UI<char>("Welcome to SUS Game", 3) {}

Player<char>* SUS_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "Human" : "Computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* SUS_UI::get_move(Player<char>* player) {
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "Enter your move (0–2 0–2): ";
        cin >> x >> y;
    }
    else { // RANDOM COMPUTER
        Board<char>* b = player->get_board_ptr();
        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}
