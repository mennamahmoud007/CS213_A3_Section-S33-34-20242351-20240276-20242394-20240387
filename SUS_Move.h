#pragma once
#include "BoardGame_Classes.h"

class SUS_Move : public Move<char> {
public:
    int playerIndex;
    SUS_Move(int x, int y, char sym, int idx) : Move<char>(x, y, sym), playerIndex(idx) {}
};
