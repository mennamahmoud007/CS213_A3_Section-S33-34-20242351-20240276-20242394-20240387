#include "Misere_UI.h"
#include <iostream>
using namespace std;

Misere_UI::Misere_UI() : UI<char>("Welcome to Misere Tic-Tac-Toe",3) {}

int Misere_UI::evaluate(Misere_Board* mb, char aiSym)
{
    Player<char> aiPlayer("AI", aiSym, PlayerType::COMPUTER);
    char oppSym = (aiSym == 'X') ? 'O' : 'X';
    Player<char> oppPlayer("Opponent", oppSym, PlayerType::COMPUTER);

    if (mb->is_lose(&aiPlayer)) return -1000;   // AI loses
    if (mb->is_lose(&oppPlayer)) return 1000;  // Opponent loses
    return 0;
}

int Misere_UI::minimax(Misere_Board* mb, char aiSym, char currentSym)
{
    vector<pair<int, int>> empties;
    for (int r = 0;r < 3;r++){
        for (int c = 0;c < 3;c++){
            if (mb->get_cell(r, c) == '.') {
                empties.push_back({ r,c });
            }
        }
    }
    if (empties.empty()) return evaluate(mb, aiSym);

    bool maximizing = (currentSym == aiSym);
    int best = maximizing ? -1000000 : 1000000;
    char nextSym = (currentSym == 'X') ? 'O' : 'X';

    for (size_t i = 0;i < empties.size();i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        mb->apply_move(r, c, currentSym);

        int val = minimax(mb, aiSym, nextSym);

        mb->undo_move(r, c);

        if (maximizing) {
            if (val > best) best = val;
        }
        else {
            if (val < best) best = val;
        }
    }

    return best;
}

void Misere_UI::choose_best_move(Misere_Board* mb, char aiSym, int& bestR, int& bestC)
{
    vector<pair<int, int>> empties;
    for (int r = 0;r < 3;r++) {
        for (int c = 0;c < 3;c++) {
            if (mb->get_cell(r, c) == '.') {
                empties.push_back({ r,c });
            }
        }
    }

    int bestScore = -1000000;
    bestR = bestC = 0;
    char oppSym = (aiSym == 'X') ? 'O' : 'X';

    for (size_t i = 0;i < empties.size();i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        mb->apply_move(r, c, aiSym);

        int score = minimax(mb, aiSym, oppSym);

        mb->undo_move(r, c);

        if (score > bestScore) {
            bestScore = score;
            bestR = r;
            bestC = c;
        }
    }
}

Player<char>* Misere_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}

Move<char>* Misere_UI::get_move(Player<char>* player) {
    int x, y;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
        return new Move<char>(x, y, player->get_symbol());
    }
    else if (player->get_type() == PlayerType::COMPUTER) {
        Board<char>* b = player->get_board_ptr();
        Misere_Board* mb = static_cast<Misere_Board*>(b);

        char aiSym = player->get_symbol();

        int r, c;
        choose_best_move(mb, aiSym, r, c);

        x = r;
        y = c;
        return new Move<char>(x, y, player->get_symbol());
    }

    
}
void Misere_UI::display_rules() {
    cout << "\n=== MISERE TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Board is 3x3" << endl;
    cout << "2. Play X and O normally" << endl;
    cout << "3. BUT forming 3 in a row makes you lose" << endl;
    cout << "4. Avoid completing any line" << endl;
    cout << "==================================" << endl;
}




//x = rand() % player->get_board_ptr()->get_rows();
//y = rand() % player->get_board_ptr()->get_columns();