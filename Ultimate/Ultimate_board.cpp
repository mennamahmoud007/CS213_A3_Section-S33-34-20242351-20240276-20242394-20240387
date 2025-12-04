#include "Ultimate_Board.h"
#include <iostream>
using namespace std;

/* -------- SubBoard -------- */
SubBoard::SubBoard() : Board<char>(3, 3) { reset(); }

void SubBoard::reset() {
    moves_count = 0;
    for (int r = 0;r < 3;++r)
        for (int c = 0;c < 3;++c)
            grid[r][c] = blank;
}

bool SubBoard::cell_empty(int r, int c) const {
    return grid[r][c] == blank;
}

char SubBoard::get_cell(int r, int c) const {
    return grid[r][c];
}

bool SubBoard::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char s = move->get_symbol();
    if (!cell_empty(x, y)) return false;
    grid[x][y] = s;
    moves_count++;
    return true;
}

bool SubBoard::is_win(Player<char>* player) {
    char s = player->get_symbol();
    for (int i = 0;i < 3;i++)
        if (grid[i][0] == s && grid[i][1] == s && grid[i][2] == s) return true;
    for (int i = 0;i < 3;i++)
        if (grid[0][i] == s && grid[1][i] == s && grid[2][i] == s) return true;
    if (grid[0][0] == s && grid[1][1] == s && grid[2][2] == s) return true;
    if (grid[0][2] == s && grid[1][1] == s && grid[2][0] == s) return true;
    return false;
}

bool SubBoard::is_draw(Player<char>* player) {
    return moves_count >= 9 && !is_win(player);
}

bool SubBoard::game_is_over(Player<char>* player) {
    if (player == nullptr) {
        // check win for X or O manually
        for (char s : {'X', 'O'}) {
            Player<char> temp("t", s, PlayerType::HUMAN);
            if (is_win(&temp)) return true;
        }
        return moves_count >= 9;
    }
    return is_win(player) || moves_count >= 9;
}


bool SubBoard::claimed() const {
    return winner() != '.';
}

char SubBoard::winner() const {
    for (char s : {'X', 'O'}) {
        for (int i = 0;i < 3;i++)
            if (grid[i][0] == s && grid[i][1] == s && grid[i][2] == s) return s;
        for (int i = 0;i < 3;i++)
            if (grid[0][i] == s && grid[1][i] == s && grid[2][i] == s) return s;
        if (grid[0][0] == s && grid[1][1] == s && grid[2][2] == s) return s;
        if (grid[0][2] == s && grid[1][1] == s && grid[2][0] == s) return s;
    }
    return '.';
}

/* -------- UltimateBoard -------- */
UltimateBoard::UltimateBoard() : Board<char>(9, 9), n_moves(0) {
    next_subboard_row = -1;   
    next_subboard_col = -1;   

    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++) {
            subs[i][j] = new SubBoard();
            mainGrid[i][j] = '.';
        }
    for (int r = 0;r < 9;r++)
        for (int c = 0;c < 9;c++)
            board[r][c] = '.';
}

UltimateBoard::~UltimateBoard() {
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            delete subs[i][j];
}

void UltimateBoard::sync_base_board() {
    for (int bi = 0;bi < 3;bi++)
        for (int bj = 0;bj < 3;bj++) {
            SubBoard* s = subs[bi][bj];
            for (int r = 0;r < 3;r++)
                for (int c = 0;c < 3;c++)
                    board[bi * 3 + r][bj * 3 + c] = s->get_cell(r, c);
        }
}

bool UltimateBoard::update_board(Move<char>* move) {
    int gx = move->get_x();
    int gy = move->get_y();
    char s = move->get_symbol();

    int bi = gx / 3, bj = gy / 3;
    int lx = gx % 3, ly = gy % 3;

    SubBoard* target = subs[bi][bj];
    if (target->claimed()) return false;

    Move<char> local(lx, ly, s);
    if (!target->update_board(&local)) return false;

    char w = target->winner();
    if (w != '.') mainGrid[bi][bj] = w;

    board[gx][gy] = s;
    sync_base_board();
    n_moves++;

    next_subboard_row = lx;
    next_subboard_col = ly;

    SubBoard* next = subs[next_subboard_row][next_subboard_col];
    if (next->game_is_over(nullptr)) {
        next_subboard_row = -1;
        next_subboard_col = -1;
    }
    return true;
}

bool UltimateBoard::is_win(Player<char>* player) {
    if(!player) return false;
    char s = player->get_symbol();
    for (int r = 0;r < 3;r++)
        if (mainGrid[r][0] == s && mainGrid[r][1] == s && mainGrid[r][2] == s) return true;
    for (int c = 0;c < 3;c++)
        if (mainGrid[0][c] == s && mainGrid[1][c] == s && mainGrid[2][c] == s) return true;
    if (mainGrid[0][0] == s && mainGrid[1][1] == s && mainGrid[2][2] == s) return true;
    if (mainGrid[0][2] == s && mainGrid[1][1] == s && mainGrid[2][0] == s) return true;
    return false;
}

bool UltimateBoard::is_draw(Player<char>* player) {
    for (int bi = 0;bi < 3;bi++)
        for (int bj = 0;bj < 3;bj++)
            if (!subs[bi][bj]->game_is_over(nullptr)) return false;
    return !is_win(player);
}

bool UltimateBoard::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

void UltimateBoard::display_board() {
    cout << "\n   0 1 2   3 4 5   6 7 8\n";
    cout << "  -------------------------\n";
    for (int br = 0;br < 3;br++) {
        for (int r = 0;r < 3;r++) {
            cout << br * 3 + r << " | ";
            for (int bc = 0;bc < 3;bc++) {
                for (int c = 0;c < 3;c++)
                    cout << board[br * 3 + r][bc * 3 + c] << " ";
                cout << "| ";
            }
            cout << "\n";
        }
        cout << "  -------------------------\n";
    }
}
