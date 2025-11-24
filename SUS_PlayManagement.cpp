#include "SUS_PlayManagement.h"
#include <algorithm>
#include <iostream>

using namespace std;

SUS_PlayManagement::SUS_PlayManagement(SUS_Player a, SUS_Player b)
    : p1(a), p2(b)
{
    bestScore = -1;
    bestBoard = vector<vector<char>>(3, vector<char>(3, '.'));
}

void SUS_PlayManagement::simulateGame() {
    rec(true);  // player1 starts
}

void SUS_PlayManagement::rec(bool turn) {
    // If board is full
    if (board.isFull()) {
        int score = board.countSUS();

        if (score > bestScore) {
            bestScore = score;
        }
        return;
    }

    char current = turn ? p1.getLetter() : p2.getLetter();

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board.isEmpty(r, c)) {

                board.place(r, c, current);

                rec(!turn);

                board.removeCell(r, c);
            }
        }
    }
}

void SUS_PlayManagement::printBest() {
    cout << "\nMaximum SUS sequences possible = " << bestScore << endl;
}
