#include "FiveByFive_UI.h"
#include <iostream>
using namespace std;

FiveByFive_UI::FiveByFive_UI() : UI<char>("Welcome to 5x5 Tic-Tac-Toe", 5) {}

int FiveByFive_UI::evaluate_board(FiveByFive_Board* fb, char aiSym)
{
    char oppSym = (aiSym == 'X') ? 'O' : 'X';

    int aiScore = fb->count_three_in_row(aiSym);
    int oppScore = fb->count_three_in_row(oppSym);

    return aiScore - oppScore;
}

int FiveByFive_UI::minimax(FiveByFive_Board* fb, char aiSym, char currentSym, int depth, int maxDepth)
{
    vector<pair<int, int>> empties = fb->get_empty_cells();

    if (empties.empty() || depth == maxDepth)
        return evaluate_board(fb, aiSym);

    bool maximizing = (currentSym == aiSym);
    char nextSym = (currentSym == 'X' ? 'O' : 'X');

    int best;
    if (maximizing) best = -1000000;
    else best = 1000000;

    for (size_t i = 0; i < empties.size(); i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        fb->apply_move(r, c, currentSym);

        int value = minimax(fb, aiSym, nextSym, depth + 1, maxDepth);

        fb->undo_move(r, c);

        if (maximizing) {
            if (value > best) best = value;
        }
        else {
            if (value < best) best = value;
        }
    }

    return best;
}

void FiveByFive_UI::choose_best_move(FiveByFive_Board* fb, char aiSym, int& bestR, int& bestC)
{
    vector<pair<int, int>> empties = fb->get_empty_cells();

    int bestScore = -1000000;
    bestR = bestC = -1;
    char oppSym = (aiSym == 'X') ? 'O' : 'X';
    int maxDepth = 3;

    for (size_t i = 0; i < empties.size(); i++) {

        int r = empties[i].first;
        int c = empties[i].second;

        fb->apply_move(r, c, aiSym);

        int score = minimax(fb, aiSym, oppSym, 1, maxDepth);

        fb->undo_move(r, c);

        if (score > bestScore) {
            bestScore = score;
            bestR = r;
            bestC = c;
        }
    }
}

Player<char>* FiveByFive_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* FiveByFive_UI::get_move(Player<char>* player) {
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 4): ";
        cin >> x >> y;
        return new Move<char>(x, y, player->get_symbol());
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        FiveByFive_Board* fb = (FiveByFive_Board*)player->get_board_ptr();

        int r, c;
        choose_best_move(fb, player->get_symbol(), r, c);

        return new Move<char>(r, c, player->get_symbol());
    }

    
}

void FiveByFive_UI::display_rules() {
    cout << "\n=== 5x5 TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 5x5" << endl;
    cout << "2. Goal is to form the most 3-in-a-row lines" << endl;
    cout << "3. Game ends after 24 moves" << endl;
    cout << "===============================" << endl;
}
