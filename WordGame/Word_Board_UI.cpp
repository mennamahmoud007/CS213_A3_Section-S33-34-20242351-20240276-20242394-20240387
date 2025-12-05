#include "Word_Board_UI.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int WordUI::evaluate_board(WordBoard* wb, char aiLetter)
{
    int totalWords = 0;

    // Check rows
    for (int i = 0; i < 3; i++) {
        string word = "";
        word += wb->get_cell(i, 0);
        word += wb->get_cell(i, 1);
        word += wb->get_cell(i, 2);
        if (wb->is_valid_word(word)) totalWords++;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        string word = "";
        word += wb->get_cell(0, j);
        word += wb->get_cell(1, j);
        word += wb->get_cell(2, j);
        if (wb->is_valid_word(word)) totalWords++;
    }

    // Diagonals
    string diag1 = "";
    diag1 += wb->get_cell(0, 0); 
    diag1 += wb->get_cell(1, 1); 
    diag1 += wb->get_cell(2, 2);
    if (wb->is_valid_word(diag1)) totalWords++;

    string diag2 = "";
    diag2 += wb->get_cell(0, 2); 
    diag2 += wb->get_cell(1, 1); 
    diag2 += wb->get_cell(2, 0);
    if (wb->is_valid_word(diag2)) totalWords++;

    return totalWords;
}

int WordUI::minimax(WordBoard* wb, char aiLetter, char currentLetter)
{
    vector<pair<int, int>> empties = wb->get_empty_cells();
    if (empties.empty()) return evaluate_board(wb, aiLetter);

    bool maximizing = (currentLetter == aiLetter);
    int best = maximizing ? -1000000 : 1000000;

    for (size_t i = 0;i < empties.size();i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        wb->apply_move(r, c, currentLetter);

        char nextLetter = currentLetter; 
        int val = minimax(wb, aiLetter, nextLetter);

        wb->undo_move(r, c);

        if (maximizing) {
            if (val > best) best = val;
        }
        else {
            if (val < best) best = val;
        }
    }

    return best;
}

void WordUI::choose_best_move(WordBoard* wb, char aiLetter, int& bestR, int& bestC)
{
    vector<pair<int, int>> empties = wb->get_empty_cells();
    int bestScore = -1000000;
    bestR = bestC = 0;

    for (size_t i = 0;i < empties.size();i++) {
        int r = empties[i].first;
        int c = empties[i].second;

        wb->apply_move(r, c, aiLetter);

        int score = minimax(wb, aiLetter, aiLetter); // next turn

        wb->undo_move(r, c);

        if (score > bestScore) {
            bestScore = score;
            bestR = r;
            bestC = c;
        }
    }
}

Player<char>* WordUI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (letters)" << endl;
    return new Player<char>(name, symbol, type);
}

Move<char>* WordUI::get_move(Player<char>* player) {
    int x, y;
    char letter;

    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nEnter row (0-2), column (0-2), and letter: ";
        cin >> x >> y >> letter;
    }
    else {
        Board<char>* b = player->get_board_ptr();
        WordBoard* wb = static_cast<WordBoard*>(b);

        char aiLetter = player->get_symbol();

        int r, c;
        choose_best_move(wb, aiLetter, r, c);

        x = r;
        y = c;
        letter = aiLetter;
    }
    return new Move<char>(x, y, letter);
}

void WordUI::display_rules() {
    cout << "\n=== WORD TIC-TAC-TOE RULES ===" << endl;
    cout << "1. Place letters to form 3-letter words" << endl;
    cout << "2. Words can be horizontal, vertical, or diagonal" << endl;
    cout << "3. First player to form a valid word wins!" << endl;
    cout << "===============================" << endl;
}