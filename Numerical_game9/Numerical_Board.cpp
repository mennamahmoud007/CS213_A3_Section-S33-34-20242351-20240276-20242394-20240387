#include "Numerical_Board.h"
#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>


using namespace std;

NumericBoard::NumericBoard() : Board(3, 3) {
    for(int i = 0; i <= 9; i++) usedNum[i] = false;

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            board[r][c] = blank_symbol;
        }
    }

    n_moves = 0;
}

bool NumericBoard::update_board(Move<int>* move) {
    if(!move) return false;

    int x = move->get_x();
    int y = move->get_y();
    int val = move->get_symbol();

    if(x < 0 || x >= 3 || y < 0 || y >= 3){
        cout << "🚫 Invalid cell: row and column must be between 0-2.\nTry again." << endl;
        return false;
    }

    if(board[x][y] != '.'){
        cout << "‼️ This Cell is already taken.\nTry again." << endl;
        return false;
    }

    if(val > 9 || val < 1){
        cout << "‼️ Numbers must be between 1-9.\nTry again." << endl;
        return false;
    }

    if(usedNum[val]){
        cout << "❌ Number " << val << " is already taken.\nTry again." << endl;
        return false;
    }

    board[x][y] = val;
    usedNum[val] = true;
    n_moves++;
    return true;
}

bool NumericBoard::line_is_win(int a, int b, int c) const {
    if (a == '.' || b == '.' || c == '.')
        return false;
    if(a + b + c == 15) return true;
    else return false;
}

bool NumericBoard::is_win(Player<int>*){
    for(int r = 0; r < 3; r++){
        if(line_is_win(board[r][0], board[r][1], board[r][2])){
            return true;
        }
    }

    for(int c = 0; c < 3; c++){
        if(line_is_win(board[0][c], board[1][c], board[2][c])){
            return true;
        }
    }

    if(line_is_win(board[0][0], board[1][1], board[2][2])) return true;
    if(line_is_win(board[0][2], board[1][1], board[2][0])) return true;

    return false;
}

bool NumericBoard::is_lose(Player<int>*) {
    return false;
}

bool NumericBoard::is_draw(Player<int>*) {
    if (n_moves < 9) return false;
    if (is_win(nullptr)) return false;
    return true;
}

bool NumericBoard::game_is_over(Player<int>* player) {
    return is_win(player) || is_draw(player);
}

vector<int> NumericBoard::available_nums(bool) const {
    vector<int> result;
    for (int i = 1; i <= 9; i++)
        if (!usedNum[i])
            result.push_back(i);
    return result;
}

vector<pair<int,int>> NumericBoard::available_cells() const {
    vector<pair<int,int>> res;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[r][c] == '.')
                res.emplace_back(r, c);
    return res;
}

vector<pair<int,int>> NumericBoard::get_winning_positions() const {
    vector<pair<int,int>> positions;

    for (int r = 0; r < 3; ++r) {
        if (line_is_win(board[r][0], board[r][1], board[r][2])) {
            positions.push_back({r, 0});
            positions.push_back({r, 1});
            positions.push_back({r, 2});
            return positions;
        }
    }
    for (int c = 0; c < 3; ++c) {
        if (line_is_win(board[0][c], board[1][c], board[2][c])) {
            positions.push_back({0, c});
            positions.push_back({1, c});
            positions.push_back({2, c});
            return positions;
        }
    }
    if (line_is_win(board[0][0], board[1][1], board[2][2])) {
        positions.push_back({0,0});
        positions.push_back({1,1});
        positions.push_back({2,2});
        return positions;
    }
    if (line_is_win(board[0][2], board[1][1], board[2][0])) {
        positions.push_back({0,2});
        positions.push_back({1,1});
        positions.push_back({2,0});
        return positions;
    }
    return positions;
}
