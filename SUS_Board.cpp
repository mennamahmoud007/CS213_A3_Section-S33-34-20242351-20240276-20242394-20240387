#include "SUS_Board.h"
#include "SUS_Move.h"
#include <iostream>

SUS_Board::SUS_Board() {
    board = std::vector<std::vector<char>>(ROWS, std::vector<char>(COLS, '-'));
    scores[0] = scores[1] = 0;
}

std::vector<std::vector<char>> SUS_Board::get_board_matrix() {
    return board;
}

bool SUS_Board::in_bounds(int r, int c) const {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

bool SUS_Board::update_board(Move<char>* m) {
    SUS_Move* move = dynamic_cast<SUS_Move*>(m);
    if (!move) return false;

    int r = move->get_row();
    int c = move->get_col();
    char sym = move->get_symbol();

    if (!in_bounds(r, c)) return false;
    if (board[r][c] != '-') return false;

    board[r][c] = sym;

    // Update score for the player who played
    int currentPlayer = sym == 'X' ? 0 : 1;
    scores[currentPlayer] += count_new_sus_sequences(r, c);

    return true;
}

int SUS_Board::count_new_sus_sequences(int r, int c) const {
    char sym = board[r][c];
    int count = 0;

    // Horizontal SUS (left-middle-right)
    if (c - 1 >= 0 && c + 1 < COLS)
        if (board[r][c - 1] == sym && board[r][c + 1] == sym)
            count++;

    // Vertical SUS
    if (r - 1 >= 0 && r + 1 < ROWS)
        if (board[r - 1][c] == sym && board[r + 1][c] == sym)
            count++;

    // Diagonal 1
    if (r - 1 >= 0 && c - 1 >= 0 && r + 1 < ROWS && c + 1 < COLS)
        if (board[r - 1][c - 1] == sym && board[r + 1][c + 1] == sym)
            count++;

    // Diagonal 2
    if (r - 1 >= 0 && c + 1 < COLS && r + 1 < ROWS && c - 1 >= 0)
        if (board[r - 1][c + 1] == sym && board[r + 1][c - 1] == sym)
            count++;

    return count;
}

bool SUS_Board::board_full() const {
    for (auto& row : board)
        for (auto cell : row)
            if (cell == '-') return false;
    return true;
}

bool SUS_Board::game_is_over(Player<char>* p) {
    return board_full();
}

bool SUS_Board::is_win(Player<char>* p) {
    int index = p->get_symbol() == 'X' ? 0 : 1;
    return scores[index] > scores[1 - index];
}

bool SUS_Board::is_draw(Player<char>* p) {
    return scores[0] == scores[1] && board_full();
}

int SUS_Board::get_score(int playerIndex) const {
    return scores[playerIndex];
}

void SUS_Board::reset_board() {
    for (auto& row : board)
        for (auto& cell : row)
            cell = '-';

    scores[0] = scores[1] = 0;
}
