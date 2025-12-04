#include "Pyramid_UI.h"
#include <iostream>

using namespace std;


PyramidUI::PyramidUI() : UI<char>("Pyramid Tic-Tac-Toe", 3) {}

Player<char>* PyramidUI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* PyramidUI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "Enter your move (row, cols): ";
        cin >> x >> y;
    }
    else {
        Board<char>* b = player->get_board_ptr();

        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}