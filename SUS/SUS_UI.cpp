#include "SUS_UI.h"
#include <iostream>
using namespace std;

int SUS_UI::p = 0;

SUS_UI::SUS_UI() : UI<char>("Welcome to S-U-S Game", 3)
{
    p = 0;
}

int SUS_UI::evaluate_board(SUS_Board* sb, char aiSym)
{
    int totalSUS = sb->count_all_SUS_sequences();
    if (aiSym == 'S') return totalSUS;
    else return -totalSUS;
}

int SUS_UI::minimax(SUS_Board* sb, char aiSym, char currentSym)
{
    vector<pair<int, int>> empties = sb->get_empty_cells();
    if (empties.empty()) return evaluate_board(sb, aiSym);

    bool maximizing = (currentSym == aiSym);
    int best;

    if (maximizing) best = -1000000;
    else best = 1000000;

    char nextSym = (currentSym == 'S') ? 'U' : 'S';

    for (size_t i = 0; i < empties.size(); i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        sb->apply_move(r, c, currentSym);

        int val = minimax(sb, aiSym, nextSym);

        sb->undo_move(r, c);

        if (maximizing) {
            if (val > best) best = val;
        }
        else {
            if (val < best) best = val;
        }
    }
    return best;
}

void SUS_UI::choose_best_move(SUS_Board* sb, char aiSym, int& bestR, int& bestC)
{
    vector<pair<int, int>> empties = sb->get_empty_cells();
    int bestScore = -1000000;
    bestR = bestC = 0;

    char oppSym = (aiSym == 'S') ? 'U' : 'S';

    for (size_t i = 0; i < empties.size(); i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        sb->apply_move(r, c, aiSym);

        // next turn is opponent
        int score = minimax(sb, aiSym, oppSym);

        sb->undo_move(r, c);

        if (score > bestScore) {
            bestScore = score;
            bestR = r;
            bestC = c;
        }
    }
}

void SUS_UI::display_rules() {
    cout << "\n=== SUS GAME RULES ===" << endl;
    cout << "1. Board is 3x3" << endl;
    cout << "2. Player 1 uses S, Player 2 uses U" << endl;
    cout << "3. Forming S-U-S scores a point" << endl;
    cout << "4. Winner is the one with the most sequences" << endl;
    cout << "========================" << endl;
}


Player<char>* SUS_UI::create_player(string& name, char symbol, PlayerType type) {
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
        SUS_Board* sb = static_cast<SUS_Board*>(b);

        char aiSym = player->get_symbol();

        int r, c;
        choose_best_move(sb, aiSym, r, c);

        x = r;
        y = c;

        
    }

    return new Move<char>(x, y, player->get_symbol());
}

