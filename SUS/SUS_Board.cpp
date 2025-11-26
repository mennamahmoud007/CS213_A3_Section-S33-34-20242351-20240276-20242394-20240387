#include "SUS_Board.h"
#include "SUS_Board.h"
#include <iostream>
using namespace std;




SUS_Board::SUS_Board() : Board(3, 3) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            board[r][c] = blank_symbol;
        }
    }
}

SUS_Board::~SUS_Board()
{
}


int SUS_Board::count_SUS_sequences(int r, int c)
{
    int count = 0;

    // Horizontal
    //for(int r = 0; r < 3; r++){
    if (board[r][0] == 'S' && board[r][1] == 'U' && board[r][2] == 'S') {
        count++;
    }
    //}
    

    // Vertical
    //for(int c = 0; c < 3; c++){
    else if (board[0][c] == 'S' && board[1][c] == 'U' && board[2][c] == 'S') {
        count++;
    }
    //}

    // Diagonals
    else if (board[0][0] == 'S' && board[1][1] == 'U' && board[2][2] == 'S') {
        count++;
    }
    else if (board[0][2] == 'S' && board[1][1] == 'U' && board[2][0] == 'S') {
        count++;
    }

    return count;
}


bool SUS_Board::update_board(Move<char>* move)
{
    int r = move->get_x();
    int c = move->get_y();
    char sym = move->get_symbol();

    if (r < 0 || r >= 3 || c < 0 || c >= 3) {
        cout << "Invalid cell: row and column must be between 0-2.\nTry again." << endl;
        return false;
    }

    if (board[r][c] != blank_symbol) {
        cout << "!!Non Empty Cell\nChoose another empty cell\n";
        return false;
    }

    board[r][c] = sym;
    n_moves++;

    int total = count_SUS_sequences(r, c);
    if (sym == 'S') {
        score_S += total;
    }
    else {
        score_U += total;
    }

    return true;
}

bool SUS_Board::is_draw(Player<char>* player)
{
    return n_moves == 9;
}

bool SUS_Board::game_is_over(Player<char>* player)
{
    return is_draw(player);
}


