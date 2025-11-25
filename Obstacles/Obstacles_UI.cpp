#include "obstacles_UI.h"
#include <iostream>

using namespace std;

ObstaclesUI::ObstaclesUI() : UI<char> ("Welcome to Obstacles Tic-Tac-Toe (6x6)", 3) {}

Player<char>* ObstaclesUI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* ObstaclesUI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "Enter your move (row(0-5), cols(0-5)): ";
        cin >> x >> y;
    }
    else {
        Board<char>* b = player->get_board_ptr();

        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}



