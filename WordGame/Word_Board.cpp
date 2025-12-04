#include "Word_Board.h"
#include <iostream>
#include <algorithm>

using namespace std;

WordBoard::WordBoard() : Board(3, 3) {
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
    load_dictionary();
}

void WordBoard::load_dictionary() {
    ifstream file("dic.txt");
    string word;
    while (file >> word) {
        if (word.length() == 3) {
            dictionary.push_back(word);
        }
    }
    file.close();
}

bool WordBoard::is_valid_word(const string& word) const {
    return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

string WordBoard::get_word(int r1, int c1, int r2, int c2, int r3, int c3) const {
    string word = "";
    word += board[r1][c1];
    word += board[r2][c2];
    word += board[r3][c3];
    return word;
}

bool WordBoard::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char letter = move->get_symbol();

    if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != blank_symbol) {
        return false;
    }

    board[x][y] = toupper(letter);
    n_moves++;
    return true;
}

bool WordBoard::is_win(Player<char>* player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        string word = get_word(i, 0, i, 1, i, 2);
        if (is_valid_word(word)) return true;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        string word = get_word(0, j, 1, j, 2, j);
        if (is_valid_word(word)) return true;
    }

    // Check diagonals
    string diag1 = get_word(0, 0, 1, 1, 2, 2);
    string diag2 = get_word(0, 2, 1, 1, 2, 0);

    return is_valid_word(diag1) || is_valid_word(diag2);
}

bool WordBoard::is_draw(Player<char>* player) {
    return (n_moves == 9 && !is_win(player));
}

bool WordBoard::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}