#include "SUS_Board.h"
#include <iostream>
using namespace std;

SUS_Board::SUS_Board() : Board<char>(3, 3) {
    for (auto& row : board)
        for (auto& cell : row)
            cell = '-';   // blank cell
}

bool SUS_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char mark = move->get_symbol();

    if (x < 0 || x >= rows || y < 0 || y >= columns)
        return false;

    if (board[x][y] != '-')   // cell must be empty
        return false;

    board[x][y] = toupper(mark);
    n_moves++;

    return true;
}

bool SUS_Board::is_win(Player<char>* player) {
    char sym = player->get_symbol();

    auto eq = [&](char a, char b, char c) {
        return a == sym && b == sym && c == sym;
        };

    // Rows
    for (int i = 0; i < 3; ++i)
        if (eq(board[i][0], board[i][1], board[i][2])) return true;

    // Columns
    for (int i = 0; i < 3; ++i)
        if (eq(board[0][i], board[1][i], board[2][i])) return true;

    // Diagonals
    if (eq(board[0][0], board[1][1], board[2][2])) return true;
    if (eq(board[0][2], board[1][1], board[2][0])) return true;

    return false;
}

bool SUS_Board::is_lose(Player<char>* player) {
    if (!player) return false;
    Board<char>* b = player->get_board_ptr();
    if (!b) return false;

    
    char other_sym = '\0';
    for (auto& row : b->get_board_matrix())
        for (auto& cell : row)
            if (cell != '-' && toupper(cell) != player->get_symbol())
                other_sym = toupper(cell);

    if (other_sym == '\0') return false; 

    Player<char> temp_other("Other", other_sym, PlayerType::HUMAN);
    temp_other.set_board_ptr(b);

    return is_win(&temp_other);
}

bool SUS_Board::is_draw(Player<char>* player) {
    return (n_moves == 9 && !is_win(player));
}

bool SUS_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

