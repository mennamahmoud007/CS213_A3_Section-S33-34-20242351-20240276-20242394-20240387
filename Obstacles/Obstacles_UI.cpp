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

void ObstaclesUI::display_rules() {
    cout << "\n=== OBSTACLES TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 6x6" << endl;
    cout << "2. Players place marks normally" << endl;
    cout << "3. After each round, 2 obstacles appear" << endl;
    cout << "4. First to connect 4 wins" << endl;
    cout << "=====================================" << endl;
}


