#include "Diamond_UI.h"
#include <iostream>

using namespace std;

Diamond_UI::Diamond_UI() : UI<char>("Welcome to Diamond Tic-Tac-Toe", 9) {}

int Diamond_UI::evaluate_board(Diamond_Board* db, char aiSym)
{
    char oppSym = (aiSym == 'X') ? 'O' : 'X';

    Player<char> aiPlayer("AI", aiSym, PlayerType::COMPUTER);
    Player<char> oppPlayer("Opponent", oppSym, PlayerType::COMPUTER);

    if (db->is_win(&aiPlayer)) return 1000;
    if (db->is_win(&oppPlayer)) return -1000;
    return 0;
}

int Diamond_UI::minimax(Diamond_Board* db, char aiSym, char currentSym, int depth, int maxDepth)
{
    vector<pair<int, int>> empties = db->get_empty_cells();
    Player<char> aiPlayer("AI", aiSym, PlayerType::COMPUTER);

    if (empties.empty() || db->is_win(&aiPlayer) || depth >= maxDepth) {
        return evaluate_board(db, aiSym);
    }

    bool maximizing = (currentSym == aiSym);
    int best = maximizing ? -1000000 : 1000000;
    char nextSym = (currentSym == 'X') ? 'O' : 'X';

    for (size_t i = 0; i < empties.size(); i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        db->apply_move(r, c, currentSym);

        int val = minimax(db, aiSym, nextSym, depth + 1, maxDepth);

        db->undo_move(r, c);

        if (maximizing) {
            if (val > best) best = val;
        }
        else {
            if (val < best) best = val;
        }
    }

    return best;
}

void Diamond_UI::choose_best_move(Diamond_Board* db, char aiSym, int& bestR, int& bestC)
{
    vector<pair<int, int>> empties = db->get_empty_cells();
    int bestScore = -1000000;
    bestR = bestC = 0;
    char oppSym = (aiSym == 'X') ? 'O' : 'X';
    int maxDepth = 3;

    for (size_t i = 0; i < empties.size(); i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        db->apply_move(r, c, aiSym);

        int score = minimax(db, aiSym, oppSym, 1, maxDepth);

        db->undo_move(r, c);

        if (score > bestScore) {
            bestScore = score;
            bestR = r;
            bestC = c;
        }
    }
}

Player<char>* Diamond_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* Diamond_UI::get_move(Player<char>* player) {
    int x, y;
    if (player->get_type() == PlayerType::HUMAN) {
        cout << "Enter row and column (0..8) for your move: ";
        cin >> x >> y;
    }
    else {
        Board<char>* b = player->get_board_ptr();
        Diamond_Board* db = static_cast<Diamond_Board*>(b);

        char aiSym = player->get_symbol();

        int r, c;
        choose_best_move(db, aiSym, r, c);

        x = r;
        y = c;
    }
    return new Move<char>(x, y, player->get_symbol());
}
void Diamond_UI::display_rules() {
    cout << "\n=== DIAMOND TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is diamond-shaped 5x5" << endl;
    cout << "2. Goal: complete two lines at once" << endl;
    cout << "3. One line must have length 3" << endl;
    cout << "4. The other must have length 4" << endl;
    cout << "===================================" << endl;
}
