#include "SUS_Board.h"
#include <iostream>

SUS_Board::SUS_Board() {
    board.assign(ROWS, std::vector<char>(COLS, ' '));
    scores[0] = scores[1] = 0;
}

std::vector<std::vector<char>> SUS_Board::get_board_matrix() {
    return board;
}

bool SUS_Board::in_bounds(int r, int c) const {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

int SUS_Board::count_new_sus_sequences(int r, int c) const {
    int found = 0;
    const int dirs[4][2] = { {1,0}, {0,1}, {1,1}, {1,-1} };
    for (int i = 0; i < 4; ++i) {
        int dx = dirs[i][0], dy = dirs[i][1];
        if (in_bounds(r - dx, c - dy) && in_bounds(r + dx, c + dy))
            if (board[r - dx][c - dy] == 'S' && board[r][c] == 'U' && board[r + dx][c + dy] == 'S') ++found;
        if (in_bounds(r + dx, c + dy) && in_bounds(r + 2 * dx, c + 2 * dy))
            if (board[r][c] == 'S' && board[r + dx][c + dy] == 'U' && board[r + 2 * dx][c + 2 * dy] == 'S') ++found;
        if (in_bounds(r - 2 * dx, c - 2 * dy) && in_bounds(r - dx, c - dy))
            if (board[r - 2 * dx][c - 2 * dy] == 'S' && board[r - dx][c - dy] == 'U' && board[r][c] == 'S') ++found;
    }
    return found;
}

bool SUS_Board::update_board(Move<char>* m) {
    SUS_Move* sm = dynamic_cast<SUS_Move*>(m);
    if (!sm) return false;

    int r = m->x;
    int c = m->y;
    char letter = m->symbol;

    if (!in_bounds(r, c)) return false;
    if (board[r][c] != ' ') return false;
    if (letter != 'S' && letter != 'U') return false;

    board[r][c] = letter;
    int gained = count_new_sus_sequences(r, c);

    int pIdx = sm->playerIndex;
    if (pIdx >= 0 && pIdx <= 1) scores[pIdx] += gained;

    return true;
}

bool SUS_Board::board_full() const {
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            if (board[r][c] == ' ') ret
