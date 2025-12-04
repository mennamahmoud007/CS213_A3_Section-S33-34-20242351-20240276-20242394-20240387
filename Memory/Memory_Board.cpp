#include "Memory_Board.h"
#include <iostream>

Memory_Board::Memory_Board() : Board(3, 3)
{
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            board[r][c] = blank_symbol;
            realBoard[r][c] = blank_symbol;
        }
    }
}

Memory_Board::~Memory_Board()
{
}

bool Memory_Board::update_board(Move<char>* move)
{
    int r = move->get_x();
    int c = move->get_y();
    char sym = move->get_symbol();

    if (r < 0 || r >= 3 || c < 0 || c >= 3) {
        cout << "Invalid cell\n";
        return false;
    }

    if (realBoard[r][c] != blank_symbol) {
        cout << "This cell is already taken.\nTry Again\n";
        return false;
    }

    realBoard[r][c] = sym;
    board[r][c] = '#';
    n_moves++;
    return true;
}

bool Memory_Board::is_win(Player<char>* player)
{
    return check_winner(player->get_symbol());
}

bool Memory_Board::is_draw(Player<char>* player)
{
    return n_moves == 9;
}

bool Memory_Board::check_winner(char sym)
{
    // rows
    for (int r = 0; r < 3; r++) {
        if (realBoard[r][0] == sym && realBoard[r][1] == sym && realBoard[r][2] == sym) {
            return true;
        }
    }

    // columns
    for (int c = 0; c < 3; c++) {
        if (realBoard[0][c] == sym && realBoard[1][c] == sym && realBoard[2][c] == sym) {
            return true;
        }
    }

    // diagonals
    if (realBoard[0][0] == sym && realBoard[1][1] == sym && realBoard[2][2] == sym) {
        return true;
    }
    if (realBoard[0][2] == sym && realBoard[1][1] == sym && realBoard[2][0] == sym) {
        return true;
    }

    return false;
}

bool Memory_Board::game_is_over(Player<char>* player)
{
    char sym = player->get_symbol();
    if (check_winner(sym)) {
        return true;
    }

    return is_draw(player);
}




