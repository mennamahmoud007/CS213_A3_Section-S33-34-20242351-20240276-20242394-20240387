#include "FiveByFive_Board.h"
#include <iostream>
using namespace std;

FiveByFive_Board::FiveByFive_Board() : Board(5, 5) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < columns; c++)
            board[r][c] = blank;
    n_moves = 0;
}

FiveByFive_Board::~FiveByFive_Board() {}

bool FiveByFive_Board::check_three_in_row(char sym, int start_r, int start_c, int dir_r, int dir_c) const {
    for (int i = 0; i < 3; i++) {
        int r = start_r + i * dir_r;
        int c = start_c + i * dir_c;
        if (r < 0 || r >= rows || c < 0 || c >= columns || board[r][c] != sym)
            return false;
    }
    return true;
}

int FiveByFive_Board::count_three_in_row(char sym) const {
    int count = 0;

    // Check horizontal
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c <= columns - 3; c++) {
            if (check_three_in_row(sym, r, c, 0, 1)) count++;
        }
    }

    // Check vertical
    for (int r = 0; r <= rows - 3; r++) {
        for (int c = 0; c < columns; c++) {
            if (check_three_in_row(sym, r, c, 1, 0)) count++;
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int r = 0; r <= rows - 3; r++) {
        for (int c = 0; c <= columns - 3; c++) {
            if (check_three_in_row(sym, r, c, 1, 1)) count++;
        }
    }

    // Check diagonals (top-right to bottom-left)
    for (int r = 0; r <= rows - 3; r++) {
        for (int c = 2; c < columns; c++) {
            if (check_three_in_row(sym, r, c, 1, -1)) count++;
        }
    }

    return count;
}

bool FiveByFive_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char sym = move->get_symbol();

    if (x < 0 || x >= rows || y < 0 || y >= columns)
        return false;

    if (board[x][y] != blank) {
        cout << "Cell is not empty.\n";
        return false;
    }

    board[x][y] = sym;
    n_moves++;
    return true;
}

bool FiveByFive_Board::is_win(Player<char>* player) {
    return false; // No early wins in 5x5
}

bool FiveByFive_Board::is_lose(Player<char>* player) {
    return false; // No loses during game
}

bool FiveByFive_Board::is_draw(Player<char>*) {
    return (n_moves == 24); // Game ends when only one square remains
}

bool FiveByFive_Board::game_is_over(Player<char>* p) {
    return is_draw(p);
}

void FiveByFive_Board::display_board() {
    cout << "\n   0   1   2   3   4\n";
    cout << "  +---+---+---+---+---+\n";

    for (int i = 0; i < rows; i++) {
        cout << i << " | ";
        for (int j = 0; j < columns; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n  +---+---+---+---+---+\n";
    }
    cout << endl;

    // Show current three-in-a-row counts
    if (n_moves > 0) {
        int x_count = count_three_in_row('X');
        int o_count = count_three_in_row('O');
        cout << "Three-in-a-row sequences - X: " << x_count << " | O: " << o_count << endl;
    }
}

void FiveByFive_Board::apply_move(int r, int c, char sym) {
    board[r][c] = sym;
    n_moves++;
}

void FiveByFive_Board::undo_move(int r, int c) {
    board[r][c] = blank;
    n_moves--;
}

vector<pair<int, int>> FiveByFive_Board::get_empty_cells() const {
    vector<pair<int, int>> cells;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            if (board[r][c] == blank) {
                cells.push_back({ r,c });
            }
        }
    }

    return cells;
}