#include "SUS_UI.h"
#include <iostream>
using namespace std;


SUS_UI::SUS_UI() : UI<char>("Welcome to S-U-S Game", 3) {}


Player<char>* SUS_UI::create_player(string& name, char symbol, PlayerType type) {
    static int p = 0;
    p++;
    char assigned = (p == 1 ? 'S' : 'U');
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << assigned << ")\n";
    return new Player<char>(name, assigned, type);
}

Move<char>* SUS_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nEnter your move (row(0-2) , col(0-2)): ";
        cin >> x >> y;
    }
    else {
        Board<char>* b = player->get_board_ptr();
        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}

void SUS_UI::print_game_result(SUS_Board& board)
{
    cout << "\n=== FINAL SCORE ===" << endl;
    cout << "Player 1 (S) score: " << board.score_S << "\n";
    cout << "Player 2 (U) score: " << board.score_U << "\n";
    if (board.score_S > board.score_U) {
        cout << "Winner: Player 1 (S)\n";
    }
    else if(board.score_U > board.score_S){
        cout << "Winner: Player 2 (U)\n";
    }
    else {
        cout << "It’s a DRAW!\n";
    }
}

