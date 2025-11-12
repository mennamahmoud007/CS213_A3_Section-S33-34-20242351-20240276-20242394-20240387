#ifndef NUMERICAL_PLAYMANAGEMENT_H
#define NUMERICAL_PLAYMANAGEMENT_H

#include "Numerical_UI.h"

class NumericalPlayManagement {
private:
    NumericBoard board;
    NumericalUI ui;
    Player<int>* p1;
    Player<int>* p2;
    Player<int>* currentPlayer;

public:
    NumericalPlayManagement();
    void run();
    void switchPlayer();
};

#endif
