#include "Misere_Board.h"
#include <iostream>
using namespace std;

Misere_Board::Misere_Board() : Board(3, 3) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < columns; c++)
            board[r][c] = blank;

    n_moves = 0;
}

Misere_Board::~Misere_Board() {}

bool Misere_Board::three_in_row(char sym) const {

    // Rows
    for (int r = 0; r < 3; r++) {
        if (board[r][0] == sym && board[r][1] == sym && board[r][2] == sym)
            return true;
    }

    // Columns
    for (int c = 0; c < 3; c++) {
        if (board[0][c] == sym && board[1][c] == sym && board[2][c] == sym)
            return true;
    }

    // Diagonals
    if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) return true;
    if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym) return true;

    return false;
}

bool Misere_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char sym = move->get_symbol();

    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        return false;

    if (board[x][y] != blank) {
        cout << "Cell is not empty.\n";
        return false;
    }

    board[x][y] = sym;
    n_moves++;
    return true;
}

bool Misere_Board::is_win(Player<char>* player) { 
    return false;
}

bool Misere_Board::is_lose(Player<char>* player) {
    return three_in_row(player->get_symbol());
}

bool Misere_Board::is_draw(Player<char>*) {
    return (n_moves == 9);
}

bool Misere_Board::game_is_over(Player<char>* p) {
    return is_lose(p) || is_draw(p);
}

void Misere_Board::apply_move(int r, int c, char sym) {
    board[r][c] = sym;
    n_moves++;
}

void Misere_Board::undo_move(int r, int c) {
    board[r][c] = blank;
    n_moves--;
}
