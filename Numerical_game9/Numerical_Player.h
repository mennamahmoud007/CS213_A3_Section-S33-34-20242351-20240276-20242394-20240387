#ifndef NUMERICAL_PLAYER_H
#define NUMERICAL_PLAYER_H

#include "BoardGame_Classes.h"
#include "Numerical_Board.h"
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

class NumericalPlayer : public Player<int> {
public:
    // oddAllowed: true => player must play odd numbers (1,3,5,7,9)
    // oddAllowed: false => player must play even numbers (2,4,6,8)
    NumericalPlayer(const std::string& n, int sym, PlayerType t, bool oddAllowed)
        : Player<int>(n, sym, t), odd(oddAllowed) {}

    // Called by CPU players to generate a valid move (respects parity & available numbers/cells).
    Move<int>* get_computer_move();

    bool number_allowed(int num) const {
        if (num < 1 || num > 9) return false;
        return odd ? (num % 2 == 1) : (num % 2 == 0);
    }

    bool is_odd_player() const { return odd; }

private:
    bool odd;
};

#endif // NUMERICAL_PLAYER_H
