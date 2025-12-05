#include "FourInARow_UI.h"
#include <iostream>

using namespace std;


FourInARow_UI::FourInARow_UI() : UI<char>("Welcome to Four-in-a-Row!", 3) {}

int FourInARow_UI::choose_best_column(FourInARow_Board* fb, char aiSym)
{
    char oppSym = (aiSym == 'X' ? 'O' : 'X');
    vector<int> valid = fb->get_valid_columns();

    for (size_t i = 0; i < valid.size(); i++) {
        int col = valid[i];
        int row = fb->get_next_open_row(col);

        fb->apply_move(col, aiSym);
        bool win = fb->check_four_in_a_row(aiSym);
        fb->undo_move(row, col);

        if (win) return col; // winning move
    }

    for (size_t i = 0; i < valid.size(); i++) {
        int col = valid[i];
        int row = fb->get_next_open_row(col);

        fb->apply_move(col, oppSym);
        bool oppWin = fb->check_four_in_a_row(oppSym);
        fb->undo_move(row, col);

        if (oppWin) return col; // block loss
    }

    for (size_t i = 0; i < valid.size(); i++) {
        int col = valid[i];
        int row = fb->get_next_open_row(col);

        fb->apply_move(col, aiSym);
        bool threat = fb->check_four_in_a_row(aiSym);  // partial check
        fb->undo_move(row, col);

        if (threat) return col;
    }

    int order[7] = { 3, 2, 4, 1, 5, 0, 6 };
    for (int i = 0; i < 7; i++) {
        int col = order[i];
        if (!fb->is_column_full(col))
            return col;
    }

    return valid[0];
}

void FourInARow_UI::display_rules() {
    cout << "\n=== Connect 4 RULES ===" << endl;
    cout << "1. Board is 6x7" << endl;
    cout << "2. Pick a column, piece falls downward" << endl;
    cout << "3. First to connect 4 wins" << endl;
    cout << "=============================" << endl;
}


Player<char>* FourInARow_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")" << endl;
    return new Player<char>(name, symbol, type);
}

Move<char>* FourInARow_UI::get_move(Player<char>* player) {
    int col;
    if (player->get_type() == PlayerType::HUMAN) {
        cout << "\nEnter the column (0 to 6) to drop your symbol: ";
        cin >> col;
    }
    else {
        Board<char>* b = player->get_board_ptr();
        FourInARow_Board* fb = dynamic_cast<FourInARow_Board*>(b);

        char aiSym = player->get_symbol();

        int col = choose_best_column(fb, aiSym);

        return new Move<char>(0, col, aiSym);
    }

    // Row will be determined by the board automatically (lowest empty slot)
    return new Move<char>(0, col, player->get_symbol());
}

void FourInARow_UI::display_board_matrix(const vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\n    ";
    for (int j = 0; j < cols; ++j)
        cout << j << "   ";
    cout << "\n  " << string(cols * 4 + 1, '-') << "\n";

    for (int i = 0; i < rows; ++i) {
        cout << i << "| ";
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " | ";
        cout << "\n  " << string(cols * 4 + 1, '-') << "\n";
    }
}

void FourInARow_UI::display_message(const string& message) {
    cout << message << endl;
}



