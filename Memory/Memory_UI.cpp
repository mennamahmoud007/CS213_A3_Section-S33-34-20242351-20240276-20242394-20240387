#include "Memory_UI.h"
#include <iostream>

using namespace std;

Memory_UI::Memory_UI() : UI<char>("Welcome to Memory Tic-Tac-Toe (3x3)", 3) {}

Player<char>* Memory_UI::create_player(string& name, char symbol, PlayerType type)
{
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* Memory_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nEnter row (0-2) and column (0-2) for your move: ";
        cin >> x >> y;
    }
    else {
        Board<char>* b = player->get_board_ptr();

        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}

void Memory_UI::display_rules() {
    cout << "\n=== MEMORY TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 3x3" << endl;
    cout << "2. Marks become hidden after being placed" << endl;
    cout << "3. Players must remember previous moves" << endl;
    cout << "4. First to align 3 hidden marks wins" << endl;
    cout << "====================================" << endl;
}
