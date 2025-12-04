#include "Ultimate_Board.h"
#include <iostream>
#include <iomanip>

using namespace std;

UltimateBoard::UltimateBoard() : Board(9, 9) {
    small_boards.resize(3, vector<vector<vector<char>>>(3,
        vector<vector<char>>(3, vector<char>(3, blank_symbol))));

    main_board.resize(3, vector<char>(3, blank_symbol));
    next_board = { -1, -1 };  // ?

    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
}

bool UltimateBoard::check_small_board_win(int board_r, int board_c, char symbol) const {
    const auto& small_board = small_boards[board_r][board_c];

    for (int i = 0; i < 3; i++) {
        if (small_board[i][0] == symbol && small_board[i][1] == symbol && small_board[i][2] == symbol)
            return true;
    }

    for (int j = 0; j < 3; j++) {
        if (small_board[0][j] == symbol && small_board[1][j] == symbol && small_board[2][j] == symbol)
            return true;
    }

    if (small_board[0][0] == symbol && small_board[1][1] == symbol && small_board[2][2] == symbol)
        return true;
    if (small_board[0][2] == symbol && small_board[1][1] == symbol && small_board[2][0] == symbol)
        return true;

    return false;
}

bool UltimateBoard::check_small_board_draw(int board_r, int board_c) const {
    const auto& small_board = small_boards[board_r][board_c];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (small_board[i][j] == blank_symbol)
                return false;
        }
    }
    return true;
}

bool UltimateBoard::is_small_board_available(int board_r, int board_c) const {
    return main_board[board_r][board_c] == blank_symbol;
}

void UltimateBoard::update_main_board_status(int board_r, int board_c, char symbol) {
    if (check_small_board_win(board_r, board_c, symbol)) {
        main_board[board_r][board_c] = symbol;
    }
    else if (check_small_board_draw(board_r, board_c)) {
        main_board[board_r][board_c] = 'D';
    }
}

bool UltimateBoard::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char mark = move->get_symbol();

    int board_r = x / 3;
    int board_c = y / 3;
    int cell_r = x % 3;
    int cell_c = y % 3;

    if (x < 0 || x >= 9 || y < 0 || y >= 9) return false;
    if (small_boards[board_r][board_c][cell_r][cell_c] != blank_symbol) return false;

    if (next_board.first != -1) {
        if (board_r != next_board.first || board_c != next_board.second) {
            cout << "You must play in board (" << next_board.first << ","
                << next_board.second << ")!" << endl;
            return false;
        }
    }

    small_boards[board_r][board_c][cell_r][cell_c] = mark;
    board[x][y] = mark;
    n_moves++;

    update_main_board_status(board_r, board_c, mark);

    next_board = { cell_r, cell_c };

    if (!is_small_board_available(next_board.first, next_board.second)) {
        next_board = { -1, -1 }; 
    }

    return true;
}

bool UltimateBoard::is_win(Player<char>* player) {
    char symbol = player->get_symbol();

    for (int i = 0; i < 3; i++) {
        if (main_board[i][0] == symbol && main_board[i][1] == symbol && main_board[i][2] == symbol)
            return true;
    }

    for (int j = 0; j < 3; j++) {
        if (main_board[0][j] == symbol && main_board[1][j] == symbol && main_board[2][j] == symbol)
            return true;
    }

    if (main_board[0][0] == symbol && main_board[1][1] == symbol && main_board[2][2] == symbol)
        return true;
    if (main_board[0][2] == symbol && main_board[1][1] == symbol && main_board[2][0] == symbol)
        return true;

    return false;
}

bool UltimateBoard::is_draw(Player<char>* player) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (main_board[i][j] == blank_symbol)
                return false;
        }
    }

    return !is_win(player);
}

bool UltimateBoard::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

void UltimateBoard::display() const {
    cout << "Ultimate Tic-Tac-Toe Board:" << endl;

    for (int big_row = 0; big_row < 3; big_row++) {
        for (int small_row = 0; small_row < 3; small_row++) {
            for (int big_col = 0; big_col < 3; big_col++) {
                for (int small_col = 0; small_col < 3; small_col++) {
                    char cell = small_boards[big_row][big_col][small_row][small_col];
                    cout << (cell == blank_symbol ? '.' : cell) << " ";
                }
                cout << "| ";
            }
            cout << endl;
        }
        cout << "------+-------+------" << endl;
    }

    cout << "\nMain Board Status:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (main_board[i][j] == blank_symbol ? '.' : main_board[i][j]) << " ";
        }
        cout << endl;
    }
}