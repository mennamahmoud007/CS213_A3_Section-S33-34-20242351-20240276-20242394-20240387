#include "SUS_Move.h"

// Constructor (already implemented inline in header, optional here)
// SUS_Move::SUS_Move(int x, int y, char sym, int idx)
    : Move<char>(x, y, sym), playerIndex(idx)
{
}

// Getter for row
int SUS_Move::get_row() const {
    return this->x;
}

// Getter for column
int SUS_Move::get_col() const {
    return this->y;
}\\
