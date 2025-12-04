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
        Pyramid_Board* sim_b = dynamic_cast<Pyramid_Board*>(b);
        
        char mySym = player->get_symbol();
        char oppSym = (mySym == 'X' ? 'O' : 'X');

        auto empties = sim_b->get_empty_cells();
        // Check your wins
        for (auto& cell : empties) {
            int r = cell.first, c = cell.second;
            sim_b->apply_move(r, c, mySym);
            bool win = sim_b->is_win_for_symbol(mySym);
            sim_b->undo_move(r, c);
            if (win) return new Move<char>(r, c, mySym);
        }

        // Check opponent wins to block them
        for (auto& cell : empties) {
            int r = cell.first, c = cell.second;
            sim_b->apply_move(r, c, oppSym);
            bool oppWins = sim_b->is_win_for_symbol(oppSym);
            sim_b->undo_move(r, c);
            if (oppWins) return new Move<char>(r, c, mySym);
        }

        if (sim_b->get_cell(1, 2) == '.') return new Move<char>(1, 2, mySym);
        if (!empties.empty()) {
            return new Move<char>(empties[0].first, empties[0].second, mySym);
        }

        x = rand() % b->get_rows();
        y = rand() % b->get_columns();
    }

    return new Move<char>(x, y, player->get_symbol());
}







/*
    x = rand() % b->get_rows();
    y = rand() % b->get_columns();
*/