#include "Word_Board.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

WordBoard::WordBoard() : Board(3, 3) {
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;

    load_dictionary();
    srand(time(0));
}

void WordBoard::load_dictionary() {
    string paths[] = {
        "dic.txt",
        "../dic.txt",
        "../../dic.txt",
        "../../../dic.txt",
        "../../../../dic.txt"
    };

    ifstream file;
    bool found = false;

    for (int i = 0; i < 5; i++) {
        file.open(paths[i]);
        if (file.is_open()) {
            found = true;
            cout << "Dictionary loaded successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Error: Cannot find dic.txt file!" << endl;
        return;
    }

    string word;

    while (file >> word) {
        if (word.length() == 3) {
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            dictionary.push_back(word);
        }
    }
    file.close();
}

bool WordBoard::is_valid_word(const string& word) const {
    return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

string WordBoard::get_word(int r1, int c1, int r2, int c2, int r3, int c3) const {
    return string(1, board[r1][c1]) + board[r2][c2] + board[r3][c3];
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
    for (int i = 0; i < 3; i++) {
        string word = get_word(i, 0, i, 1, i, 2);
        if (word[0] != '.' && word[1] != '.' && word[2] != '.') {
            if (is_valid_word(word)) {
                cout << "Player wins with word: " << word << endl;
                return true;
            }
        }
    }

    for (int j = 0; j < 3; j++) {
        string word = get_word(0, j, 1, j, 2, j);
        if (word[0] != '.' && word[1] != '.' && word[2] != '.') {
            if (is_valid_word(word)) {
                cout << "Player wins with word: " << word << endl;
                return true;
            }
        }
    }

    string diag1 = get_word(0, 0, 1, 1, 2, 2);
    string diag2 = get_word(0, 2, 1, 1, 2, 0);

    if (diag1[0] != '.' && diag1[1] != '.' && diag1[2] != '.') {
        if (is_valid_word(diag1)) {
            cout << "Player wins with word: " << diag1 << endl;
            return true;
        }
    }

    if (diag2[0] != '.' && diag2[1] != '.' && diag2[2] != '.') {
        if (is_valid_word(diag2)) {
            cout << "Player wins with word: " << diag2 << endl;
            return true;
        }
    }

    return false;
}

bool WordBoard::test_move(int r, int c, char letter) const {
    vector<vector<char>> temp_board = board;
    temp_board[r][c] = toupper(letter);

    auto temp_get_word = [&temp_board](int r1, int c1, int r2, int c2, int r3, int c3) {
        return string(1, temp_board[r1][c1]) + temp_board[r2][c2] + temp_board[r3][c3];
        };

    vector<string> test_words;

    test_words.push_back(temp_get_word(r, 0, r, 1, r, 2));
    test_words.push_back(temp_get_word(0, c, 1, c, 2, c));

    if (r == c) test_words.push_back(temp_get_word(0, 0, 1, 1, 2, 2));
    if (r + c == 2) test_words.push_back(temp_get_word(0, 2, 1, 1, 2, 0));

    for (const auto& word : test_words) {
        if (word[0] != '.' && word[1] != '.' && word[2] != '.') {
            if (is_valid_word(word)) return true;
        }
    }

    return false;
}

bool WordBoard::is_draw(Player<char>* player) {
    return (n_moves == 9 && !is_win(player));
}

bool WordBoard::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

void WordBoard::apply_move(int r, int c, char letter) {
    board[r][c] = toupper(letter);
    n_moves++;
}

void WordBoard::undo_move(int r, int c) {
    board[r][c] = blank_symbol;
    n_moves--;
}

vector<pair<int, int>> WordBoard::get_empty_cells() const {
    vector<pair<int, int>> empties;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == blank_symbol) {
                empties.push_back({ r, c });
            }
        }
    }
    return empties;
}