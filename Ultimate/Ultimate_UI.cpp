#include "Ultimate_UI.h"
#include <iostream>

using namespace std;

Ultimate_UI::Ultimate_UI() : UI<char>("Welcome to Ultimate Tic-Tac-Toe",9) {
}

Player<char>* Ultimate_UI::create_player(string& name, char symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";
    return new Player<char>(name, symbol, type);
}


Move<char>* Ultimate_UI::get_move(Player<char>* player) {
    if (!player) return nullptr;

    UltimateBoard* ub = dynamic_cast<UltimateBoard*>(player->get_board_ptr());
    if (!ub) return nullptr;

    auto mat = ub->get_board_matrix();

    // HUMAN case
    if (player->get_type() == PlayerType::HUMAN) {
        int x, y;
        while (true) {
            ub->display_board();

            if (ub->next_subboard_row == -1) {
                cout << "\n" << player->get_name() << " (" << player->get_symbol()
                    << ") enter move anywhere (row col 0-8): ";
            }
            else {
                int r = ub->next_subboard_row * 3;
                int c = ub->next_subboard_col * 3;
                cout << "\n" << player->get_name() << " (" << player->get_symbol()
                    << ") enter move in sub-board starting at rows(" << r << "-" << r + 2 << "), cols(" << c << "-" << c + 2 << "): ";
            }

            cin >> x >> y;

            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid input\n"; continue; }
            if (x < 0 || x > 8 || y < 0 || y > 8) { cout << "Coordinates out of range (0..8)\n"; continue; }

            int bi = x / 3, bj = y / 3;
            bool free_subboard = (ub->next_subboard_row == -1 && ub->next_subboard_col == -1);
            bool correct_subboard = (bi == ub->next_subboard_row && bj == ub->next_subboard_col);

            if (!(free_subboard || correct_subboard)) {
                cout << "You must play in sub-board " << ub->next_subboard_row
                    << "," << ub->next_subboard_col << "\n";
                continue;
            }

            if (mat[x][y] != '.') {
                cout << "Cell occupied! Try again.\n";
                continue;
            }

            return new Move<char>(x, y, player->get_symbol());
        }
    }

    // COMPUTER case
    vector<pair<int, int>> candidates;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (mat[i][j] != '.') continue;
            int bi = i / 3, bj = j / 3;
            bool free_subboard = (ub->next_subboard_row == -1 && ub->next_subboard_col == -1);
            bool correct_subboard = (bi == ub->next_subboard_row && bj == ub->next_subboard_col);
            if (free_subboard || correct_subboard)
                candidates.push_back({ i,j });
        }
    }

    if (candidates.empty()) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (mat[i][j] == '.')
                    candidates.push_back({ i,j });
    }

    if (candidates.empty()) return nullptr;

    auto p = candidates[rand() % candidates.size()];
    cout << "Computer (" << player->get_symbol() << ") plays: " << p.first << " " << p.second << "\n";

    
    return new Move<char>(p.first, p.second, player->get_symbol());
}

