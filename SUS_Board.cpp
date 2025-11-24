#include "SUS_Board.h"
#include <iostream>

SUS_Board::SUS_Board() {
    grid = vector<vector<char>>(3, vector<char>(3, '.'));
}

bool SUS_Board::isFull() {
    for (auto& row : grid)
        for (auto& c : row)
            if (c == '.') return false;
    return true;
}

bool SUS_Board::isEmpty(int r, int c) {
    return grid[r][c] == '.';
}

void SUS_Board::place(int r, int c, char ch) {
    grid[r][c] = ch;
}

void SUS_Board::removeCell(int r, int c) {
    grid[r][c] = '.';
}

int SUS_Board::countSUS() {
    int cnt = 0;
    string t = "SUS";

    // horizontal
    for (int i = 0; i < 3; i++) {
        string row = "";
        for (int j = 0; j < 3; j++) row += grid[i][j];
        if (row == t) cnt++;
    }

    // vertical
    for (int j = 0; j < 3; j++) {
        string col = "";
        for (int i = 0; i < 3; i++) col += grid[i][j];
        if (col == t) cnt++;
    }

    // diagonals
    string d1 = "";
    for (int i = 0; i < 3; i++) d1 += grid[i][i];
    if (d1 == t) cnt++;

    string d2 = "";
    for (int i = 0; i < 3; i++) d2 += grid[i][2 - i];
    if (d2 == t) cnt++;

    return cnt;
}

void SUS_Board::print() {
    for (auto& row : grid) {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
    cout << "------------------\n";
}
