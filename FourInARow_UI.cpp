#include "FourInARow_UI.h"

FourInARow_UI::FourInARow_UI() : UI<char>("Welcome to Four-in-a-Row!", 3) {}

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
        col = rand() % 7; // random column
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
