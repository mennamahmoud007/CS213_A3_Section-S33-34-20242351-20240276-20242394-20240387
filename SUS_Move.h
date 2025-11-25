#pragma once
#include "BoardGame_Classes.h"

class SUS_Move : public Move<char> {
private:
    int row;
    int col;
    char symbol;

public:
    int playerIndex;

    SUS_Move(int x, int y, char sym, int idx)
        : Move<char>(x, y, sym), row(x), col(y), symbol(sym), playerIndex(idx) {}

    int get_row() const { return row; }
    int get_col() const { return col; }
    char get_symbol() const { return symbol; }
};
