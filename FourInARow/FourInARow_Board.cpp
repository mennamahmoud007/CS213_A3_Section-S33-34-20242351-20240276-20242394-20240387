#include "FourInARow_Board.h"
#include <iostream>
using namespace std;

FourInARow_Board::FourInARow_Board()
    : Board<char>(6, 7) // 6 صفوف و7 أعمدة
{
    // تهيئة اللوحة بالفراغات
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            board[i][j] = ' ';
}

FourInARow_Board::~FourInARow_Board() {}

bool FourInARow_Board::update_board(Move<char>* move) {
    int col = move->get_y();
    char symbol = move->get_symbol();

    
    for (int row = rows - 1; row >= 0; --row) {
        if (board[row][col] == ' ') {
            board[row][col] = symbol;
            ++n_moves;
            return true;
        }
    }
    // العمود ممتلئ
    return false;
}

bool FourInARow_Board::check_four_in_a_row(char symbol) {
 
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j <= columns - 4; ++j)
            if (board[i][j] == symbol && board[i][j + 1] == symbol &&
                board[i][j + 2] == symbol && board[i][j + 3] == symbol)
                return true;

   
    for (int i = 0; i <= rows - 4; ++i)
        for (int j = 0; j < columns; ++j)
            if (board[i][j] == symbol && board[i + 1][j] == symbol &&
                board[i + 2][j] == symbol && board[i + 3][j] == symbol)
                return true;

    for (int i = 0; i <= rows - 4; ++i)
        for (int j = 0; j <= columns - 4; ++j)
            if (board[i][j] == symbol && board[i + 1][j + 1] == symbol &&
                board[i + 2][j + 2] == symbol && board[i + 3][j + 3] == symbol)
                return true;

    for (int i = 3; i < rows; ++i)
        for (int j = 0; j <= columns - 4; ++j)
            if (board[i][j] == symbol && board[i - 1][j + 1] == symbol &&
                board[i - 2][j + 2] == symbol && board[i - 3][j + 3] == symbol)
                return true;

    return false;
}

bool FourInARow_Board::is_win(Player<char>* player) {
    return check_four_in_a_row(player->get_symbol());
}

bool FourInARow_Board::is_lose(Player<char>* player) {
  
    char opponent_symbol = (player->get_symbol() == 'X') ? 'O' : 'X';
    return check_four_in_a_row(opponent_symbol);
}

bool FourInARow_Board::is_draw(Player<char>* player) {
    return n_moves == rows * columns && !is_win(player) && !is_lose(player);
}

bool FourInARow_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_lose(player) || is_draw(player);
}

vector<vector<char>>& FourInARow_Board::get_board_matrix() {
    return board;
}

void FourInARow_Board::apply_move(int r, int c, char sym) {
    board[r][c] = sym;
    n_moves++;
}

void FourInARow_Board::undo_move(int r, int c) {
    board[r][c] = blank;
    n_moves--;
}

vector<pair<int, int>> FourInARow_Board::get_empty_cells() const {
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