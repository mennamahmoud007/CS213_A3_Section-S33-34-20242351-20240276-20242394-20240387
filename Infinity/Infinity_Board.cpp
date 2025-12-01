#include "Infinity_Board.h"
#include <iostream>
using namespace std;

Infinity_Board::Infinity_Board() : Board(3, 3) {
    n_moves = 0;
    for (int r = 0;r < 3;r++)
        for (int c = 0;c < 3;c++)
            board[r][c] = blank;
}

Infinity_Board::~Infinity_Board() {}

bool Infinity_Board::three_in_row(char sym) const {
    // rows
    for (int r = 0;r < 3;r++)
        if (board[r][0] == sym && board[r][1] == sym && board[r][2] == sym)
            return true;

    // columns
    for (int c = 0;c < 3;c++)
        if (board[0][c] == sym && board[1][c] == sym && board[2][c] == sym)
            return true;

    // diagonals
    if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) return true;
    if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym) return true;

    return false;
}

bool Infinity_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char sym = move->get_symbol();

    if (x < 0 || x >= 3 || y < 0 || y >= 3) return false;
    if (board[x][y] != blank) {
        cout << "Cell is not empty.\n";
        return false;
    }

    board[x][y] = sym;
    moves.push({ x,y });
    n_moves++;

   if (n_moves > 3 && n_moves % 3 == 0) {
        remove_oldest();
    }

    return true;
}

void Infinity_Board::remove_oldest() {
    if (moves.empty()) return;
    auto old = moves.front(); 
    moves.pop();
    board[old.first][old.second] = blank;
}

bool Infinity_Board::is_win(Player<char>* player) {
    return three_in_row(player->get_symbol());
}

bool Infinity_Board::is_lose(Player<char>*) {
    return false;
}

bool Infinity_Board::is_draw(Player<char>*) {
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[r][c] == blank)
                return false; 
    return true; 
}

bool Infinity_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

void Infinity_Board::display_board() {
    cout << "\n   0 1 2\n";
    for (int r = 0;r < 3;r++) {
        cout << r << " ";
        for (int c = 0;c < 3;c++)
            cout << board[r][c] << " ";
        cout << "\n";
    }
}
