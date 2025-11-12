#include "Numerical_Board.h"
#include <iostream>
using namespace std;

NumericBoard::NumericBoard() : Board<int>(3, 3) {
    for (int i = 0; i < 10; ++i) usedNum[i] = false;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            board[i][j] = '.';
}

bool NumericBoard::line_is_win(int a, int b, int c) const {
    if (a == '.' || b == '.' || c == '.') return false;
    return (a + b + c == 15);
}

bool NumericBoard::update_board(Move<int>* move) {
    int r = move->row;
    int c = move->col;
    int val = move->value;

    if (r < 0 || r >= rows || c < 0 || c >= cols || usedNum[val] || board[r][c] != '.')
        return false;

    board[r][c] = val;
    usedNum[val] = true;
    return true;
}

bool NumericBoard::is_win(Player<int>* player) {
    for (int i = 0; i < 3; ++i)
        if (line_is_win(board[i][0], board[i][1], board[i][2]) ||
            line_is_win(board[0][i], board[1][i], board[2][i]))
            return true;

    return line_is_win(board[0][0], board[1][1], board[2][2]) ||
        line_is_win(board[0][2], board[1][1], board[2][0]);
}

bool NumericBoard::is_draw(Player<int>* player) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (board[i][j] == '.')
                return false;
    return true;
}

bool NumericBoard::game_is_over(Player<int>* player) {
    return is_win(player) || is_draw(player);
}

vector<pair<int, int>> NumericBoard::available_cells() const {
    vector<pair<int, int>> cells;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (board[i][j] == '.')
                cells.push_back({ i, j });
    return cells;
}

vector<int> NumericBoard::available_nums(bool unused) const {
    vector<int> nums;
    for (int i = 1; i <= 9; ++i)
        if (!usedNum[i])
            nums.push_back(i);
    return nums;
}

vector<pair<int, int>> NumericBoard::get_winning_positions() const {
    vector<pair<int, int>> win;
    for (int i = 0; i < 3; ++i) {
        if (line_is_win(board[i][0], board[i][1], board[i][2]))
            return { {i,0},{i,1},{i,2} };
        if (line_is_win(board[0][i], board[1][i], board[2][i]))
            return { {0,i},{1,i},{2,i} };
    }
    if (line_is_win(board[0][0], board[1][1], board[2][2]))
        return { {0,0},{1,1},{2,2} };
    if (line_is_win(board[0][2], board[1][1], board[2][0]))
        return { {0,2},{1,1},{2,0} };
    return win;
}
