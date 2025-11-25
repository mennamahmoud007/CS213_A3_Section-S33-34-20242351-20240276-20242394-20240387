#include "SUS_Board.h"

SUS_Board::SUS_Board() : Board<char>(3, 3) {
    for (auto& row : board)
        for (auto& cell : row)
            cell = '-';
}

bool SUS_Board::update_board(Move<char>* move, Player<char>* player) {
    int x = move->get_x();
    int y = move->get_y();
    char sym = toupper(move->get_symbol());

    if (x < 0 || x >= rows || y < 0 || y >= columns) return false;
    if (board[x][y] != '-') return false;

    board[x][y] = sym;
    n_moves++;

    // تحديث النقاط
    int sequences = count_sus_sequences();
    if (player->get_symbol() == 'S') p1_score = sequences;
    else p2_score = sequences;

    return true;
}

bool SUS_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char sym = toupper(move->get_symbol());

    if (x < 0 || x >= rows || y < 0 || y >= columns) return false;
    if (board[x][y] != '-') return false;

    board[x][y] = sym;
    n_moves++;
    return true;
}

bool SUS_Board::is_draw(Player<char>* player) {
    return n_moves == 9;
}

bool SUS_Board::game_is_over(Player<char>* player) {
    return n_moves == 9;
}

int SUS_Board::count_sus_sequences() {
    int count = 0;

    // الصفوف
    for (int i = 0; i < 3; i++)
        if (board[i][0] == 'S' && board[i][1] == 'U' && board[i][2] == 'S') count++;

    // الأعمدة
    for (int j = 0; j < 3; j++)
        if (board[0][j] == 'S' && board[1][j] == 'U' && board[2][j] == 'S') count++;

    // الأقطار
    if (board[0][0] == 'S' && board[1][1] == 'U' && board[2][2] == 'S') count++;
    if (board[0][2] == 'S' && board[1][1] == 'U' && board[2][0] == 'S') count++;

    return count;
}

int SUS_Board::get_score(Player<char>* player) {
    if (player->get_symbol() == 'S') return p1_score;
    return p2_score;
}

