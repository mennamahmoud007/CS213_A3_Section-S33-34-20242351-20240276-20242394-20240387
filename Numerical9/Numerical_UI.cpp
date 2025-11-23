#include <iostream>
#include <iomanip>
#include "Numerical_UI.h"

void NumericalUI::display_board(const NumericBoard& board) const {
    int rows = 3;
    int cols = 3;
    int cell_width = 2;

    auto winning_positions = board.get_winning_positions();

    cout << "\n    ";
    for (int j = 0; j < cols; ++j)
        cout << setw(cell_width + 1) << j;
    cout << "\n   " << string((cell_width + 2) * cols, '-') << "\n";

    for (int i = 0; i < rows; ++i) {
        cout << setw(2) << i << " |";
        for (int j = 0; j < cols; ++j) {
            int cell = board.get_cell(i, j);
            char display_char = (cell == '.') ? '.' : '0' + cell;

            bool is_winning_cell = false;
            for (auto& pos : winning_positions)
                if (pos.first == i && pos.second == j)
                    is_winning_cell = true;

            if (is_winning_cell)
                cout << "\033[31m"; //red
            else
                cout << "\033[0m";

            cout << setw(cell_width) << display_char << " |";
        }
        cout << "\033[0m";
        cout << "\n   " << string((cell_width + 2) * cols, '-') << "\n";
    }
    cout << endl;
}

Player<int>* NumericalUI::create_player(string& name, int symbol, PlayerType type) {
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name;

    if (symbol == 0)
        cout << " (EVEN numbers player)\n";
    else
        cout << " (ODD numbers player)\n";

    return new Player<int>(name, symbol, type);
}

Move<int>* NumericalUI::get_move(Player<int>* player) {
    int x, y, val;

    // symbol = 0 ? EVEN numbers only
    // symbol = 1 ? ODD numbers only
    bool isEvenPlayer = (player->get_symbol() == 0);

    while (true) {
        if (player->get_type() == PlayerType::HUMAN) {
            cout << "\nEnter row (0-2), column (0-2), and number (1-9): ";
            cin >> x >> y >> val;
        }
        else {
            // Random position
            Board<int>* board = player->get_board_ptr();
            x = rand() % board->get_rows();
            y = rand() % board->get_columns();

            // Random number respecting parity
            if (isEvenPlayer) {
                int evens[] = { 2, 4, 6, 8 };
                val = evens[rand() % 4];
            }
            else {
                int odds[] = { 1, 3, 5, 7, 9 };
                val = odds[rand() % 5];
            }
        }

        // Block wrong parity
        if (isEvenPlayer && val % 2 != 0) {
            cout << "? You can only choose EVEN numbers (2,4,6,8).\n";
            continue;
        }
        if (!isEvenPlayer && val % 2 != 1) {
            cout << "? You can only choose ODD numbers (1,3,5,7,9).\n";
            continue;
        }

        return new Move<int>(x, y, val);
    }
}

void NumericalUI::print_game_result(NumericBoard& board) {
    cout << "Game over!\n";
    if (board.is_draw(nullptr)) cout << "It's a draw!\n";
    else cout << "We have a winner!\n";
}
